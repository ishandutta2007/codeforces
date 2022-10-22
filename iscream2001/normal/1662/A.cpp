#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int a[N],b[N],f[N],n,m,mx[N];
int main()
{
    int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=10;++i)mx[i]=-1;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a[i],&b[i]);
			mx[b[i]]=max(mx[b[i]],a[i]);
		}
		int tag=0;
		for(int i=1;i<=10;++i){
			if(mx[i]==-1)tag=1;
	    }
		int ans=0;
		for(int i=1;i<=10;++i)ans+=mx[i];
		if(tag)puts("MOREPROBLEMS");
		else 
		printf("%d\n",ans);
	}
	return 0;
}