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
vector<int> gen(int a,int b,int c)
{
	vector<int> v;
	v.pb(a);
	v.pb(b);
	v.pb(c);
	v.pb(a+b);
	v.pb(a+c);
	v.pb(b+c);
	v.pb(a+b+c);
	srt(v);
	return v;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> b;
		for(int i=0;i<7;i++)
		{
			int x;
			cin>>x;
			b.pb(x);
		}
		for(int i=0;i<7;i++)
			for(int j=0;j<7;j++)
				for(int k=0;k<7;k++)
					if(gen(b[i],b[j],b[k])==b)
					{
						cout<<b[i]<<" "<<b[j]<<" "<<b[k]<<endl;
						goto end;
					}
		end:;
	}
	return 0;
}