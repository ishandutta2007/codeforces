#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int N, Q;
int A[202020];
int cnt[202020];
pii M[202020];
vector<piii> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	cin >> N >> Q;
	for (int i=1; i<=N; i++) {
		cin >> A[i]; cnt[A[i]]++;
		if (M[A[i]].va == 0) M[A[i]].va = i;
		M[A[i]].vb = i;
	}

	for (int i=1; i<202020; i++) {
		if (M[i].va != 0) v.emplace_back(M[i], i);
	}

	v.emplace_back(pii(1<<30, 1<<30), 1<<30);
	sort(v.begin(), v.end());

	int l=1, r;
	int ans = 0;
	vector<int> tmp;
	for (int i=0; i<v.size(); i++) {
		pq.push(pii(v[i].va.vb, v[i].vb));
		while (pq.top().va < v[i].va.va) {
			r = pq.top().va;
			tmp.push_back(pq.top().vb); pq.pop();
		}

		if (pq.size() == 1 && tmp.size() != 0) {
			int mx = 0;
			for (auto x : tmp)
				mx = max(mx, cnt[x]);
			ans += (r-l+1)-mx;
			tmp.clear(); l=r+1;
		}
	}

	cout << ans;
}