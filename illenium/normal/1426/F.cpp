#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll da[maxn],db[maxn],dc[maxn],n,ans,num;
char s[maxn];
const ll mod=1000000007;

int main()
{
	cin>>n; scanf("%s",s+1); num=1;
	rep(i,1,n)
	{
		da[i]=da[i-1]; db[i]=db[i-1]; dc[i]=dc[i-1];
		if(s[i]=='a') da[i]=(da[i]+num)%mod;
		else if(s[i]=='b') db[i]=(db[i]+da[i-1])%mod;
		else if(s[i]=='c') dc[i]=(dc[i]+db[i-1])%mod;
		else
		{
			da[i]=(3*da[i-1]+num)%mod;
			db[i]=(3*db[i-1]+da[i-1])%mod;
			dc[i]=(3*dc[i-1]+db[i-1])%mod; num=(num*3)%mod;
		}
	}
	cout<<dc[n]<<endl;
	return 0;
}