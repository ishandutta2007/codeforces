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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if((a+b)%2)
		{
			int x=(a+b)/2;
			int y=x+1;
			set<int> s;
			for(int i=max(0,a-y);i<=min(a,x);i++)
			{
				int j=a-i;
				s.insert(i+y-j);
			}
			swap(x,y);
			for(int i=max(0,a-y);i<=min(a,x);i++)
			{
				int j=a-i;
				s.insert(i+y-j);
			}
			vector<int> v;
			while(!s.empty())
			{
				v.pb(*s.begin());
				s.erase(s.begin());
			}
			cout<<sz(v)<<endl;
			for(int i=0;i<sz(v);i++)
				cout<<v[i]<<" ";
			puts("");
		}
		else
		{
			int x=(a+b)/2;
			vector<int> v;
			for(int i=max(0,a-x);i<=min(a,x);i++)
			{
				int j=a-i;
				v.pb(i+x-j);
			}
			srt(v);
			cout<<sz(v)<<endl;
			for(int i=0;i<sz(v);i++)
				cout<<v[i]<<" ";
			puts("");
		}
	}
	return 0;
}