#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

long double deg[10010],length[10010],nowdeg;
const long double pi=3.141592653589793238462643383279;
int n,q,t1=1,t2=2;
struct node{
	long double x,y;
	long double operator*(node a){return x*a.y-y*a.x;}
	node operator+(node a){return (node){x+a.x,y+a.y};}
	node operator-(node a){return (node){x-a.x,y-a.y};}
	node operator/(long double tem){return (node){x/tem,y/tem};}
	node operator*(long double tem){return (node){x*tem,y*tem};}
}Pos[10010],center;
long double cross(node a,node b,node c){return (b-a)*(c-a);}
node getpos(int x){
	long double Deg=deg[x]+nowdeg;
	while(Deg>=pi*2.)Deg-=pi*2.;
	while(Deg<=-pi*2.)Deg+=pi*2.;
	return (node){center.x+length[x]*sin(Deg),center.y+length[x]*cos(Deg)};
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%Lf%Lf",&Pos[i].x,&Pos[i].y);
	long double sum=0.;
	for(int i=3;i<=n;i++){
		long double area=cross(Pos[1],Pos[i-1],Pos[i]);
		sum+=area;
		center=center+(Pos[i-1]+Pos[i]-(Pos[1]*2.))/3.*area;
	}
	center=(center/sum)+Pos[1];
	for(int i=1;i<=n;i++){
		long double a=Pos[i].x-center.x,b=Pos[i].y-center.y,c=sqrt(a*a+b*b);
		deg[i]=.5*pi-atan2(b,a);
		length[i]=c;
		while(deg[i]>=pi*2.)deg[i]-=pi*2.;
		while(deg[i]<=-pi*2.)deg[i]+=pi*2.;
	}
	nowdeg=0.;
//	for(int i=1;i<=n;i++)printf("%.10Lf %.10Lf\n",deg[i],length[i]);
	for(int i=1,opt,f,t;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&f,&t);
			if(t1==f)t1^=t2^=t1^=t2;
			center=getpos(t1);
			nowdeg=0.-deg[t1];
			center.y-=length[t1];
			t2=t;
		}
		else{
			scanf("%d",&f);
			auto x=getpos(f);
			std::cout<< std::setprecision(11) << x.x << ' ' << x.y << std::endl;
		}
//		for(int i=1;i<=n;i++)printf("(%.10Lf %.10Lf)",getpos(i).x,getpos(i).y);putchar('\n');
	}
}