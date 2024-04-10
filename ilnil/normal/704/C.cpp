#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define P pair<int,int>
#define abs(x)(x>0?x:-(x))
#define F first
#define S second
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n,m,ans[2],k,x,y,f[2][2],g[2][2],ans2[2];
vector<P>a[N];
vector<int>dy[N];
vector<int>b[N];
bool bz[N];
int main(){
	cin>>n>>m;
	fo(i,1,n){
		scanf("%d%d",&k,&x);
		if(k==1){
			b[abs(x)].push_back(x);
		}else{
			scanf("%d",&y);
			dy[abs(x)].push_back(a[abs(y)].size());
			dy[abs(y)].push_back(a[abs(x)].size());
			a[abs(x)].push_back(P(x,y));
			a[abs(y)].push_back(P(y,x));
		}
	}
	ans[0]=1;
	fo(i,1,m)if(!bz[i]){
		if(!b[i].size()&&!a[i].size()){
			fo(o,0,1)ans[o]=ans[o]*2%mo;
			continue;
		}
		if(b[i].size()||a[i].size()==1){
			if(b[i].size()==2){
				f[0][0]=f[0][1]=0;
				fo(o,0,1){
					x=(b[i][0]<0?!o:o)^(b[i][1]<0?!o:o);
					f[0][x]+=ans[0];
					f[0][!x]+=ans[1];
				}
				fo(o,0,1)ans[o]=f[0][o]%mo;
				continue;
			}
			if(b[i].size()==1){
				fo(o,0,1){
					x=b[i][0]<0?!o:o;
					f[o][x]=ans[0];f[o][!x]=ans[1];
				}
			}else fo(o,0,1)f[o][0]=ans[0],f[o][1]=ans[1];
			bz[i]=1;
			if(a[i].size()){
				x=dy[i][0];
				for(int j=abs(a[i][0].S),las=i;;){
					bz[j]=1;
					fo(o,0,1)fo(u,0,1)g[o][u]=0;
					fo(o,0,1)
						fo(u,0,1){
							y=(a[j][x].F<0?!o:o)|(a[j][x].S<0?!u:u);
							g[o][y]+=f[u][0];
							g[o][!y]+=f[u][1];
						}
					if(b[j].size()){
						fo(o,0,1){
							y=b[j][0]<0?!o:o;
							if(y)swap(g[o][0],g[o][1]);
						}
					}
					fo(o,0,1)fo(u,0,1)f[o][u]=g[o][u]%mo;
					if(b[j].size()||a[j].size()==1)break;
					las=j;j=abs(a[j][!x].S);x=dy[las][!x];
				}
			}
			fo(o,0,1)ans[o]=(f[0][o]+f[1][o])%mo;
		}
	}
	fo(i,1,m)if(!bz[i]&&a[i].size()==2){
		bz[i]=1;
		ans2[0]=ans2[1]=0;
		fo(st,0,1){
			fo(o,0,1)fo(u,0,1)f[o][u]=0;
			f[st][0]=ans[0];f[st][1]=ans[1];
			x=dy[i][0];
			for(int j=abs(a[i][0].S),las=i;;){
				bz[j]=1;
				if(j==i){
					fo(o,0,1)fo(u,0,1){
						y=(a[j][x].F<0?!st:st)|(a[j][x].S<0?!o:o);
						(ans2[y^u]+=f[o][u])%=mo;
					}
					break;
				}
				fo(o,0,1)fo(u,0,1)g[o][u]=0;
				fo(o,0,1)
					fo(u,0,1){
						y=(a[j][x].F<0?!o:o)|(a[j][x].S<0?!u:u);
						g[o][y]+=f[u][0];
						g[o][!y]+=f[u][1];
					}
				fo(o,0,1)fo(u,0,1)f[o][u]=g[o][u]%mo;
				las=j;j=abs(a[j][!x].S);x=dy[las][!x];
			}
		}
		fo(o,0,1)ans[o]=ans2[o];
	}
	cout<<ans[1];
}