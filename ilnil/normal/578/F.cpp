#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define _(x,y)((x)*(m+1)+(y))
#define P pair<int,int>
#define ll long long
using namespace std;
const int N=405;
int n,m,mo,f[N*N],be[N*N],bs,x,y,ans;
int g[N][N];
vector<P>e[2];
string a;
int F(int x){return x==f[x]?x:f[x]=F(f[x]);}
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>mo;
	fo(i,0,_(n,m))f[i]=i;
	fo(i,1,n){
		cin>>a;
		fo(j,1,m){
			if(a[j-1]=='*'){
				e[i+j&1].push_back(P(_(i-1,j-1),_(i,j)));
				e[i+j+1&1].push_back(P(_(i,j-1),_(i-1,j)));	
			}else{
				if(a[j-1]=='\\')x=F(_(i-1,j-1)),y=F(_(i,j));
				else x=F(_(i-1,j)),y=_(i,j-1);
				if(x==y)return puts("0"),0;
				f[x]=y;
			}
		}
	}
	fo(o,0,1){
		bs=0;
		memset(g,0,sizeof g);
		fo(i,0,n)fo(j,0,m)if((i+j&1)==o&&F(_(i,j))==_(i,j))be[_(i,j)]=++bs;
		for(auto i:e[o]){
			x=F(i.first);y=F(i.second);
			if(x!=y)
				--g[be[x]][be[y]],--g[be[y]][be[x]],++g[be[x]][be[x]],++g[be[y]][be[y]];
		}
		fo(i,1,bs)fo(j,1,bs)g[i][j]%=mo;
		int cnt=1;
		fo(i,1,bs-1){
			if(!g[i][i])
				fo(j,i+1,bs-1)if(g[j][i]){
					swap(g[i],g[j]);
					cnt=-cnt;
					break;
				}
			cnt=(ll)cnt*g[i][i]%mo;
			if(!cnt)break;
			int iv=ksm(g[i][i],mo-2);
			fo(j,i+1,bs-1)if(g[j][i]){
				int ny=(ll)iv*g[j][i]%mo;
				fo(k,i+1,bs-1)g[j][k]=(-(ll)ny*g[i][k]+g[j][k])%mo;
			}
		}
		ans=(ans+cnt+mo)%mo;
	}
	cout<<ans;
}