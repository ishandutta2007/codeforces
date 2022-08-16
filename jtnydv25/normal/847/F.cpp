#include <bits/stdc++.h>
using namespace std;

struct trip {
	int freq, idx, last;
	trip(int a=0, int b=0, int c=0) : freq(a), idx(b), last(c) {}
	bool operator < (trip ot) const {
		return (freq == ot.freq) ? (last < ot.last) : (freq > ot.freq);
	}
};

const int N = 105;

int n, k, m, a;
trip vote[N];
int sum[N], ind[N];

int main() {
	cin >> n >> k >> m >> a;
	for (int i=1; i<=n; i++) {
		vote[i].idx = i;
	}
	for (int i=1, t; i<=a; i++) {
		cin >> t;
		vote[t].last = i;
		vote[t].freq++;
	}
	sort(vote+1, vote+n+1);
	for (int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + vote[i].freq;
		ind[vote[i].idx] = i;
	}
	if (a == m) {
		for (int i=1; i<=n; i++)
			cout << ((ind[i]<=k && vote[ind[i]].freq>0) ? "1 " : "3 ");
		cout << endl;
		return 0;
	}
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	if (k == n) {
		for (int i=1; i<=n; i++)
			cout << (vote[ind[i]].freq ? "1 " : "2 ");
		cout << endl;
		return 0;
	}
	int rem = m - a;
	for (int i=1; i<=n; i++) {
		// check for no chances
		int pos = ind[i];
		int votes = vote[pos].freq + rem;
		int rnk = upper_bound(vote+1, vote+n+1, trip(votes,i,m)) - vote;
		if (rnk > k) {
			cout << "3 ";
			continue;
		}
		// check for sure chance
		if (pos <= k && (vote[pos].freq+1)*(k+1-pos) - (sum[k+1]-sum[pos]) > rem) {
			cout << (vote[pos].freq ? "1 " : "2 ");
		}
		else
			cout << "2 ";
	}
	cout << endl;

	return 0;
}