#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

#define pi 3.1415926535897932384626

int i,j,k,n,m,t,sb1,sb2,sb0,yes;
long double x[100500],y[100500],res=1e19,l,r,md;

bool chk(long double r){
	int i,j,k;
	long double h=-1e18,h2=1e18,x1,y1,y2,d,nmsl;
	for(i=1;i<=n;i++){
		x1=x[i]-r;
		x1=fabs(x1);
		y1=y[i];
		d=(r*r-x1*x1);
		if(d<0){return 0;}
		nmsl=sqrt(r-x1)*sqrt(r+x1);
		y2=y1-nmsl;
		h=max(h,y2);
		h2=min(h2,y1+nmsl);
	}
	//printf("a%Lf %Lf %Lf\n",r,h,h2);
	return h<=h2;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&k,&j);
		if(j<0){sb1++;}
		if(j>0){sb2++;}
		if(j==0){sb0++;}
		x[i]=abs(j);y[i]=k;
	}
	if(sb0>1||(sb1&&sb2)){
		puts("-1");return 0;
	}
	l=0;r=1e18;
	t=200;
	while(t--){
		md=(l+r)/2;
		if(chk(md)){
			res=min(res,md);yes=1;r=md;
		}
		else{
			l=md;
		}
	}
	if(!yes){return 1;}
	printf("%.20Lf",res);
}