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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> ZFunction(string s)
{
	int n=sz(s);
	vector<int> Z(n);
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		if(i<=r)
		{
			if(Z[i-l]<r-i+1)
				Z[i]=Z[i-l];
			else
			{
				Z[i]=r-i+1;
				while(i+Z[i]<n&&s[i+Z[i]]==s[Z[i]]) Z[i]++;
			}
		}
		else
		{
			Z[i]=0;
			while(i+Z[i]<n&&s[i+Z[i]]==s[Z[i]]) Z[i]++;
		}
		if(i+Z[i]-1>r)
		{
			l=i;
			r=i+Z[i]-1;
		}
	}
	return Z;
}
int main()
{
	string s;
	cin>>s;
	if(sz(s)==1)
		die("Just a legend");
	vector<int> ZF=ZFunction(s);
	vector<int> NZF,vec;
	for(int i=0;i<sz(s);i++)
	{
		if(ZF[i]==sz(s)-i)
			vec.pb(sz(s)-i),
			NZF.pb(ZF[i]-1);
		else NZF.pb(ZF[i]);
	}
	rsrt(NZF);
	vec.pb(-1);
	srt(vec);
//	for(auto x:vec)
//		cout<<x<<endl;
//	puts("");
//	for(auto x:NZF)
//		cout<<x<<endl;
	for(auto x:NZF)
		if(vec[ub(vec,x)-1]>0)
			die(s.substr(0,vec[ub(vec,x)-1]));
	die("Just a legend");
	return 0;
}