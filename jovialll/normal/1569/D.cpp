#include<bits/stdc++.h>
using namespace std;
#define l(x) (x&-x)
#define N 1000005
int c[N],las,LAS,rv[N],r_[N],x[N],y[N],cnt,tot,X[N],Y[N];
struct node{
	int f1,f2;
}nd[N],n_[N];
inline bool cmp(node aa,node bb){
	if(aa.f2==bb.f2)return aa.f1<bb.f1;
	return aa.f2<bb.f2;
}
long long ans;
void add(int x,int y){while(x<N)c[x]+=y,x+=l(x);}
int sum(int x){int ret=0;while(x)ret+=c[x],x-=l(x);return ret;}
int T,n,m,k,i,xx,yy,V;
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;ans=0;
		for(i=1;i<=n;++i)cin>>x[i],rv[x[i]]=i;
		for(i=1;i<=m;++i)cin>>y[i],r_[y[i]]=i;
		x[n+1]=1e9;y[m+1]=1e9;
		tot=cnt=0;
		for(i=1;i<=k;++i){
			cin>>xx>>yy;
			if(rv[xx]&&r_[yy])continue;
//			cout<<xx<<" "<<yy<<'?';
			if(rv[xx])nd[++cnt].f1=rv[xx],nd[cnt].f2=lower_bound(y+1,y+m+1,yy)-y;
			else n_[++tot].f1=r_[yy],n_[tot].f2=lower_bound(x+1,x+n+1,xx)-x;
		}
		sort(nd+1,nd+cnt+1,cmp);nd[cnt+1].f2=-1;
		las=LAS=0;
		for(i=1;i<=cnt;++i){
//			cout<<nd[i].f1<<' '<<nd[i].f2<<"++\n";
			if(nd[i].f2!=nd[i+1].f2){
				ans+=1ll*(LAS-las)*(i-LAS);
				las=LAS=i;
			}
			else if(nd[i].f1!=nd[i+1].f1){
				ans+=1ll*(LAS-las)*(i-LAS);
				LAS=i;
			}
		}
		sort(n_+1,n_+tot+1,cmp);n_[tot+1].f2=-1;
		las=LAS=0;
		for(i=1;i<=tot;++i){
			if(n_[i].f2!=n_[i+1].f2){
				ans+=1ll*(LAS-las)*(i-LAS);
				las=LAS=i;
			}
			else if(n_[i].f1!=n_[i+1].f1){
				ans+=1ll*(LAS-las)*(i-LAS);
				LAS=i;
			}
		}
		cout<<ans<<"\n";
		for(i=1;i<=n;++i)rv[x[i]]=0;
		for(i=1;i<=m;++i)r_[y[i]]=0;
	}
}