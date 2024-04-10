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
int a[500500],b[500500],c[500500];
int to[500500];
int main()
{
	for(int i=1;i<=500000;i++)
		to[i]=i;
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]==2)
			cin>>c[i];
	}
	vector<int> v;
	for(int i=q-1;i>=0;i--)
	{
		if(a[i]==2)
		{
			to[b[i]]=to[c[i]];
		}
		else	v.pb(to[b[i]]);
	}
	rev(v);
	for(auto x:v)
		cout<<x<<" ";
	return 0;
}