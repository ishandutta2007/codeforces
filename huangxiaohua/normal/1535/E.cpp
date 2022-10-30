#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,del[305000],f[300500][25],it,sb,t;
ll a[300500],c[300500],r1,r2,lim,tmp;

int main(){
	ios::sync_with_stdio(0);
	scanf("%d%lld%lld",&t,&a[0],&c[0]);
	memset(f,-1,sizeof(f));
	for(int T=1;T<=t;T++){
		scanf("%d",&it);
		if(it==1){
			scanf("%d%lld%lld",&sb,&a[T],&c[T]);
			f[T][0]=sb;
			for(i=1;i<=20;i++){
				f[T][i]=f[f[T][i-1]][i-1];
				if(f[T][i]==-1){break;}
				//printf("a%d %d %d\n",T,i,f[T][i]);
			}
		}
		else{
			scanf("%d%lld",&sb,&lim);
			r1=r2=0;
			while(r1<lim&&!del[sb]){
				it=sb;
				for(i=19;i>=0;i--){
					if(f[it][i]!=-1&&!del[f[it][i]]){it=f[it][i];}
				}
				tmp=min(a[it],lim-r1);
				a[it]-=tmp;
				r1+=tmp;
				r2+=tmp*c[it];
				if(!a[it]){del[it]=1;}
			}
			printf("%lld %lld\n",r1,r2);
			fflush(stdout);
		}
	}
}