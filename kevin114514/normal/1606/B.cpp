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
	scanf("%d",&t);
	while(t--)
	{
		ll n,k;
		scanf("%lld%lld",&n,&k);
		n--;
		ll t=0;
		ll x=1;
		for(;x<k&&n>0;t++,n-=x,x*=2);
		printf("%lld\n",(n+k-1)/k+t);
	}
	return 0;
}