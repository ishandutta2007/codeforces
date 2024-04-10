#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
const int E=400; 

int n,m;

int a[N],be[N];

int F[N],T[N];

void MAIN(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		be[i]=(i+E-1)/E; 
	}
	for(int now=1;now<be[n];++now){
		for(int i=E*now;i>E*(now-1);i--){
			if(i+a[i]<=E*now){
				F[i]=F[i+a[i]];
				T[i]=T[i+a[i]]+1;
			}
			else{
				F[i]=i;
				T[i]=0;
			}
		}
	}
	int op,u,v,ans;
	while(m--){
		scanf("%d",&op);
		if(op==0){
			scanf("%d%d",&u,&v);
			a[u]=v;
			if(be[u]==be[n]) continue;
			u=be[u];
			for(int i=E*u;i>E*(u-1);--i){
				if(i+a[i]<=E*u){
					F[i]=F[i+a[i]];
					T[i]=T[i+a[i]]+1;
				}
				else{
					F[i]=i;
					T[i]=0;
				}
			}
		}
		else{
			scanf("%d",&u);
			ans=0;
			while(1){
				if(be[u]!=be[n]){
					ans+=T[u];
					u=F[u];
					if(u+a[u]<=n){
						++ans;
						u=u+a[u];
					}
					else{
						break;
					}
				}
				else{
					if(u+a[u]<=n){
						++ans;
						u=u+a[u];
					}
					else{
						break;
					}
				}
			}
			printf("%d %d\n",u,ans+1);
		}
	}
	return;
}
int main(){
	int ttt=1;
	while(ttt--) MAIN();
    return 0;
}