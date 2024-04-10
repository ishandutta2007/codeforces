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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(k==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				cout<<i<<endl;
		}
		else if(n%2)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			int odd=1,even=2;
			for(int i=1;i<=n;i++)
			{
				if(i%2)
					for(int j=0;j<k;j++,odd+=2)
						cout<<odd<<" ";
				else
					for(int j=0;j<k;j++,even+=2)
						cout<<even<<" ";
				puts("");
			}
		}
	}
	return 0;
}