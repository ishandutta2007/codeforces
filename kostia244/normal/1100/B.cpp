#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define LL long long
#define MAX 100010

int n, k, t, tn, cn = 0;
vi num;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> k >> n;
	num.resize(k, 0);
	for(int i = 0; i < n; i++) {
		cin >> t;
		if(++num[t - 1] == 1) {
			cn++;
		}
		if(cn == k) {
			cout << 1;
			for(int j = 0; j < k; j++)
				if(--num[j] == 0)
					cn--;
		} else {
			cout << 0;
		}
	}
}