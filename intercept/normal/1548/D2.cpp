#include<bits/stdc++.h>
using namespace std;
const int M=6009;
int n;
int x[M],y[M],cnt[4][4][4];
long long ans[2];
int C(int a,int b,int c,int d){
	return ((a*d-c*b)%4+4)%4;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i!=j)cnt[((x[j]-x[i])%4+4)%4][((y[j]-y[i])%4+4)%4][__gcd(abs(x[j]-x[i]),abs(y[j]-y[i]))%4]++;
		}
		for(int a=0;a<4;++a){
			for(int b=0;b<4;++b){
				for(int c=0;c<4;++c){
					for(int u=a&1;u<4;u+=2){
						for(int v=b&1;v<4;v+=2){
							for(int w=c&1;w<4;w+=2){
								int s=cnt[a][b][c],t=cnt[u][v][w],z=__gcd(abs(a-u),abs(b-v));
								if(a==u&&b==v&&c==w)t--;
								if((c+w+z)%4==C(a,b,u,v))ans[w&1]+=1ll*s*t;
							}
						}
					}
				}
			}
		}
		memset(cnt,0,sizeof(cnt));
	}
	printf("%lld\n",ans[0]/6+ans[1]/2);
	return 0;
}