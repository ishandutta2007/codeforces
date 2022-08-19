#include <cstdio>
#include <cmath>
#include <algorithm>

double pi=acos(-1.0);
int n,rr,x[3001],y[3001],num[3001];
double L[3001],R[3001];
bool vis[3001];
bool ins[3001];
int main(){
	scanf("%d%d",&n,&rr);
	for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i),vis[i]=1,L[i]=-pi-1e-5,R[i]=pi+1e-5,ins[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j])<=1.0*rr*rr)continue;
			double a=atan2((double)(y[j]-y[i]),(double)(x[j]-x[i])),b=atan2((double)rr,sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j])-1.0*rr*rr));
			double l=a-b-1e-5,r=a+b+1e-5;
			if(l<-pi)l+=2.*pi;
			if(r>pi)r-=2.*pi;
			// printf("%d %d %lf %lf\n",i,j,a,b);
			if(!ins[i]){
				L[i]=l;
				R[i]=r;
				ins[i]=1;
				continue;
			}
			if(L[i]<R[i]){
				if(l<r){
					L[i]=std::fmax(l,L[i]);
					R[i]=std::fmin(r,R[i]);
					if(L[i]>R[i])vis[i]=0;
				}
				else
					if(l>L[i]&&l<R[i])L[i]=l;
					else if(r>L[i]&&r<R[i])R[i]=r;
					else if(l>R[i]&&r<L[i])vis[i]=0;
			}
			else{
				if(l<r){
					std::swap(l,L[i]);
					std::swap(r,R[i]);
					if(l>L[i]&&l<R[i])L[i]=l;
					else if(r>L[i]&&r<R[i])R[i]=r;
					else if(l>R[i]&&r<L[i])vis[i]=0;
				}
				else{
					L[i]=std::fmax(l,L[i]);
					R[i]=std::fmin(r,R[i]);
					if(L[i]<R[i])vis[i]=0;
				}
			}
		}
	// for(int i=1;i<=n;++i)printf("%d %lf %lf\n",vis[i],L[i],R[i]);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			if(!vis[i]||!vis[j])continue;
			double v=atan2(y[j]-y[i],x[j]-x[i]);
			// printf("%lf\n",v);
			if(L[i]>R[i]){
				if(v>=L[i]||v<=R[i]);
				else continue;
			}
			else{
				if(v>=L[i]&&v<=R[i]);
				else continue;
			}
			v=atan2(y[i]-y[j],x[i]-x[j]);
			// printf("%lf\n",v);
			if(L[j]>R[j]){
				if(v>=L[j]||v<=R[j]);
				else continue;
			}
			else{
				if(v>=L[j]&&v<=R[j]);
				else continue;
			}
			// printf("%d %d\n",i,j);
			++ans;
		}
	printf("%d\n",ans);
}