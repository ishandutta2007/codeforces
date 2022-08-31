#include <algorithm>
#include <cstdio>
#include <cmath>
#define double long double

double eps=1e-7;
int n,t[100001];
int intx[100001],inty[100001];
double x[100001],y[100001],e1,e2,w,h;
double getleft(double X,int i,double L,double R,double d){
	double l=0.,r=X,mid,ans=X;
	while(r-l>=1e-8){
		mid=(l+r)/2.0;
		double b=mid+(x[i]-mid)*h/(y[i])-(x[i-1]*h/y[i-1]),k=(h/y[i-1]-1.);
		double nl=std::max(mid-d,(-b-d)/k),nr=std::min(mid+d,(d-b)/k);
		if(std::max(nl,L)-eps<=std::min(nr,R))ans=mid,r=mid;
		else l=mid;
	}
//	printf("getleft %Lf %d %Lf %Lf %Lf %Lf\n",X,i,L,R,d,ans);
	return ans;
}
double getright(double X,int i,double L,double R,double d){
	double l=X,r=w,mid,ans=X;
	while(r-l>=1e-8){
		mid=(l+r)/2.0;
		double b=mid+(x[i]-mid)*h/(y[i])-(x[i-1]*h/y[i-1]),k=(h/y[i-1]-1.);
		double nl=std::max(mid-d,(-b-d)/k),nr=std::min(mid+d,(d-b)/k);
		if(std::max(nl,L)-eps<=std::min(nr,R))ans=mid,l=mid;
		else r=mid;
	}
//	printf("getright %Lf %d %Lf %Lf %Lf %Lf\n",X,i,L,R,d,ans);
	return ans;
}
bool judge(double u){
//	printf("judge %Lf\n",u);
	double l=e1,r=e1;
	for(int i=1,last=-1;i<=n;i++){
		if(t[i]==t[i-1]){
			if(x[i]==x[last]&&y[i]==y[last])continue;
			if(y[i]==y[last])return 0;
			double x1=x[i]-(x[last]-x[i])*y[i]/(y[last]-y[i]);
//			printf("%Lf %.20Lf %.20Lf %d\n",l,r,x1-1e-8,x1-1e-8<=r);
			if(x1+1e-8<l||x1-1e-8>r)return 0;
			l=r=x1;
			continue;
		}else last=i;
		double d=u*(t[i]-t[i-1]);
		double b,k;
		b=l+(x[i-1]-l)*h/(y[i-1])-(x[i]*h/y[i]),k=(h/y[i]-1.);
		double nl1=std::max(l-d,(-b-d)/k),nr1=std::min(l+d,(d-b)/k);
		b=r+(x[i-1]-r)*h/(y[i-1])-(x[i]*h/y[i]),k=(h/y[i]-1.);
		double nl2=std::max(r-d,(-b-d)/k),nr2=std::min(r+d,(d-b)/k);
		if(nl1-eps<=nr1){
			double l0=getleft(nl1,i,l,r,d),r0=getright(nl1,i,l,r,d);
			l=l0,r=r0;
		}
		else if(nl2-eps<=nr2){
			double l0=getleft(nl2,i,l,r,d),r0=getright(nl2,i,l,r,d);
			l=l0,r=r0;
		}
		else{
			if(y[i-1]==y[i])return 0;
			double X=(x[i]*y[i-1]-x[i-1]*y[i])/(y[i-1]-y[i]);
			if(X+eps<l||X-eps>r)return 0;
			double l0=getleft(X,i,l,r,d),r0=getright(X,i,l,r,d);
			l=l0,r=r0;
		}
		l=std::max(l,(double)0.),r=std::min(r,w);
//		printf("%Lf %Lf %Lf %Lf %Lf\n",u,l,r,-x[i]*h/(y[i]-h),(w*y[i]-x[i]*h)/(y[i]-h));
		r=std::min(r,-x[i]*h/(y[i]-h));
		l=std::max(l,(w*y[i]-x[i]*h)/(y[i]-h));
		if(l-eps>r)return 0;
	}
	return 1;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%Lf%Lf",&n,&w,&h);
	scanf("%Lf%Lf",&e1,&e2);
	t[0]=0,x[0]=e2,y[0]=h;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",t+i,intx+i,inty+i);
		x[i]=(double)intx[i];
		y[i]=(double)inty[i];
	}
	for(int i=1;i<=n;i++){
		int j=i,p=0;
		while(j<n&&t[j+1]==t[i]){
			++j;
			if(intx[i]!=intx[j]||inty[i]!=inty[j]){
				if(inty[i]==inty[j]){
					puts("-1");
					return 0;
				}
				if(!p)p=j;
				else if(intx[p]!=intx[j]||inty[p]!=inty[j]){
					if(inty[p]==inty[j]){
						puts("-1");
						return 0;
					}
					if((inty[p]-inty[j])*(intx[p]-intx[i])!=(inty[p]-inty[i])*(intx[p]-intx[j])){
						puts("-1");
						return 0;
					}
				}
			}
		}
		if(p){
			double X=x[i]-(x[p]-x[i])*y[i]/(y[p]-y[i]);
			if(X<0.||X>w){
				puts("-1");
				return 0;
			}
			X=x[i]-(x[p]-x[i])*(y[i]-h)/(y[p]-y[i]);
			if(X<0.||X>w){
				puts("-1");
				return 0;
			}
		} 
		i=j;
	}
	double l=0.,r=1000.,mid,ans=w;
	while(fabs(r-l)>=1e-5){
		mid=(l+r)/2.0;
		if(judge(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(ans==-1.)puts("-1");
	else printf("%.5Lf\n",ans);
}