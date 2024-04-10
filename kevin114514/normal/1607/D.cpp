#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
int a[200200];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		string s;
		cin>>s;
		vector<int> r,b;
		for(int i=0;i<n;i++)
			if(s[i]=='R')
				r.pb(a[i]);
			else	b.pb(a[i]);
		bool fl=0;
		srt(b);
		for(int i=0;i<sz(b);i++)
			if(b[i]<=i)
				fl=1;
		rsrt(r);
		for(int i=0;i<sz(r);i++)
			if(r[i]>n-i)
				fl=1;
		if(fl)
			puts("NO");
		else	puts("YES");
	}
	return 0;
}