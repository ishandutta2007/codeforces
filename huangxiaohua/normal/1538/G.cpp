#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
ll x,y,a,b,l,r,md1,md2;
double f1,f2,res;

double get(ll sb){
	double res=sb,xx,yy;
	xx=x-a*sb;
	yy=y-b*sb;
	res+=min(xx/(double)b,yy/(double)a);
	return res;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		l=0;r=min(x/a,y/b);res=0;
		while(l<=r){
			md1=l+(r-l)/3;
			md2=l+(r-l)*2/3;
			f1=get(md1);
			f2=get(md2);
			
			//printf("%d %d %d %d\n",l,md1,md2,r);
			if(f2>=f1){
				res=max(res,f2);
				l=md1+1;
			}
			else{
				res=max(res,f1);
				r=md2-1;
			}
		}
		printf("%lld\n",(long long)(res));
	}
}