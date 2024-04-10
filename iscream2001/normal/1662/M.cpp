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
		scanf("%d%d",&n,&m);
		int mx1=0,mx2=0;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&a[i],&b[i]);
			mx1=max(mx1,a[i]);
			mx2=max(mx2,b[i]);
		}
		if(mx1+mx2>n){
			printf("IMPOSSIBLE\n");
		}
		else{
			for(int i=1;i<=mx1;++i)printf("R");
			for(int i=1;i<=n-mx1;++i)printf("W");
			puts("");
		}
		
	}
	return 0;
}