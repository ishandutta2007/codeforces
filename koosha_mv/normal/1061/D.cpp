#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N = 1e5 + 5, P = 1e9 + 7;
pair<int, int> a[N];
int n,x,y,ans;
multiset<int> s;
 
int main() {
	ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		auto it = s.lower_bound(a[i].first);
		if (!s.empty() && it-- != s.begin() && 1LL * (a[i].first - *it) * y < x)
			ans = (1LL * y * (a[i].first - *it) - x + ans + P) % P, s.erase(it);
		ans = (1LL * y * (a[i].second - a[i].first) + x + ans) % P, s.insert(a[i].second);
	}
	cout << ans << endl;
 
	return 0;
}