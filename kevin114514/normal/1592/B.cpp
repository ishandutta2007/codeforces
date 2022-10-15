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
		vector<int> v;
		vector<int> u;
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			v.pb(x-1);
		}
		u=v;
		srt(u);
		bool flag=true;
		for(int i=0;i<n;i++)
			if(v[i]!=u[i])
				if(i-d<0&&i+d>=n)
					flag=false;
		if(flag)
			puts("YES");
		else	puts("NO");
	}
	return 0;
}