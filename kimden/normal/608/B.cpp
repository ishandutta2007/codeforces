#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 100002;

int main()
{
	/*int n,k;
	cin >> n >> k;
	int ans=0,a,b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ans = max(ans,a+b);
	}
	cout << ans;*/
	string s,t;
	ll ans = 0;
	cin >> s >> t;
	int n = s.length(),m = t.length();
	int c0=0,m0=0,c1,m1;
	for(int i=0;i<m;i++){
		if(t[i]=='0'){
			m0++;
		}
	}
	for(int i=0;i<n-1;i++){
		if(t[m-n+1+i]=='0'){
			c0++;
		}
	}
	c1 = n-1-c0;
	m1 = m-m0;
	for(int i=0;i<n;i++){
		ans += (s[i] == '0' ? m1 : m0);
		ans -= (s[i] == '0' ? c1 : c0);
		c0 -= (t[m-n+1+i] == '0' ? 1 : 0);
		c0 += (t[i] == '0' ? 1 : 0);
		c1 = n-1-c0;
	}
	cout << ans;
}