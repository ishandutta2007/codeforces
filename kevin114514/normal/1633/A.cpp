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
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(x<100)
		{
			int ans=10;
			int res=0;
			for(int j=14;j<99;j+=7)
				if((x%10!=j%10)+(x/10!=j/10)<ans)
				{
					ans=(x%10!=j%10)+(x/10!=j/10);
					res=j;
				}
			cout<<res<<endl;
		}
		else
		{
			int ans=10;
			int res=0;
			for(int j=105;j<999;j+=7)
				if((x%10!=j%10)+(x/10%10!=j/10%10)+(x/100!=j/100)<ans)
				{
					ans=(x%10!=j%10)+(x/10%10!=j/10%10)+(x/100!=j/100);
					res=j;
				}
			cout<<res<<endl;
		}
	}
	return 0;
}