#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

pair<int, int> a[100009];
ll A, B;

ll ps(int s, int e, int ts, int te)
{
	long long l = (e - s + 1), p = te - ts + 1, hp = B * p * l;
	if (l == 1) return hp;
	int md = (s + e) / 2;
	if (md < a[ts].first || a[te].first <= md) {
		if (md < a[ts].first) return min(ps(md + 1, e, ts, te) + A, hp);
		else return min(ps(s, md, ts, te) + A, hp);
	}
	int pm = (*lower_bound(a + ts, a + te, make_pair(md, 1000000000))).second;
	pm--;
	return min(hp, ps(s, md, ts, pm) + ps(md + 1, e, pm + 1, te));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n, k; cin >> n >> k >> A >> B;
	for (int i = 1; i <= k; i++) 
		cin >> a[i].first;
	sort(a + 1, a + k + 1);
	for (int i = 1; i <= k; i++)
		a[i].second = i;
	cout << ps(1, (1 << n), 1, k) << '\n';
	return 0;
}