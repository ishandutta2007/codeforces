#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

#define int ll

const int maxn=3e5+1000;
ll a[maxn];
ll p[2];
int n;
ll Cnt[maxn];
ll A[maxn],ans;
signed main()
{
	cin>>n;
	ll mx,Sum;
	int i=0;
  ORZYYB:i++;
	{
		cin>>a[i];
		REP(j,0,61)Cnt[i]+=a[i]>>j&1; mx=Cnt[i];
		mx=Sum=A[i]=Cnt[i];
		DREP(j,i-1,max(1ll,i-65))
		{
			mx=max(mx,Cnt[j]); Sum+=Cnt[j];
			if(mx+mx<=Sum&&~Sum&1) ans++; A[j]+=Cnt[i];
		}
		if(Cnt[i]&1)  swap(p[0],p[1]);
		ans+=p[0];
		if(i>65){
			p[A[i-65]&1]++;
		}
	}
	if(i<n)goto ORZYYB;
	printf("%lld\n",ans);
	return 0;
}