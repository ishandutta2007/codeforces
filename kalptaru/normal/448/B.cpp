#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) int a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		string s,d;
		cin>>s>>d;
		int n,m,j=0,f[26]={0},g[26]={0};
		n=s.size();
		m=d.size();
		bool ar=0;
		FOR(i,0,n)
		{
			if(s[i]==d[j]){j++;if(j==m){cout<<"automaton";return 0;}}
			f[s[i]-'a']++;
		}
		FOR(i,0,m)
		f[d[i]-'a']--;
		FOR(i,0,26)
		{
			if(f[i]<0){cout<<"need tree";return 0;}
		}
		if(n==m)cout<<"array";
		else cout<<"both";
		
	}
}