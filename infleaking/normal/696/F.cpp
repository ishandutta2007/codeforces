#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int N=605;
const ld eps=1e-15;
struct dot{ld x,y;}a[N];
struct line{dot u,v;}p[N],q[N];
ld cross(dot a,dot b){return a.x*b.y-a.y*b.x;}
ld dot1(dot a,dot b){return a.x*b.x+a.y*b.y;}
ld dis(dot a){return sqrt(a.x*a.x+a.y*a.y);}
dot operator+(dot a,dot b){return (dot){a.x+b.x,a.y+b.y};}
dot operator-(dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
dot operator*(dot a,ld x){return (dot){a.x*x,a.y*x};}
ld cross0(line a,line b){
	return (ld)cross(b.u-a.u,b.v)/cross(a.v,b.v);
}
vector<line> h,h1;
dot z1=(dot){-3.1415926535,2.718281828},z2,z0;
int push(line a){
	if (cross(a.v,z2-a.u)<-eps||h.empty()){
		ld mx=1e9,mn=-1e9;
		for (int i=0;i<h.size();i++){
			if (abs(cross(a.v,h[i].v))<eps){
				if (dot1(a.v,h[i].v)<0){
					if (cross(h[i].u-a.u,a.v)>0){
						return -1;
					}
				}
				continue;
			}
			ld q=cross0(a,h[i]);
			if (cross(a.v,h[i].v)>0) mx=min(mx,q);
			else mn=max(mn,q);
		}
		if (mx<mn-eps)return 1;
		if (cross(a.v,z1))z2=a.u+a.v*mn;
		else z2=a.u+a.v*mx;
		h.push_back(a);
		return 0;
	}
	else {
		h.push_back(a);
		return 0;
	}
}
void clear(){
	h=h1;
	z2=z0;
}
int n;
int ansl,ansr;
dot adj(dot a,ld len){return a*(len/dis(a));}
dot R(dot a){return (dot){-a.y,a.x};}
int check(ld lim){
	static int ri[N];
	for (int i=1;i<=n;i++)q[i]=q[i+n]=(line){p[i].u+adj(R(p[i].v),lim),R(R(p[i].v))},ri[i]=ri[i+n]=0;
	for (int i=1,j;i<=n;i++){
		for (j=i;j<=i+n;j++){
			if (push(q[j])){
				j--;
				clear();
				break;
			}
		}
		if (j==i+n)clear();
		ri[i]=j;
		ri[i+n]=j+n;
	}
	for (int i=1;i<=n;i++){
		if (ri[ri[i]+1]>=i+n-1){
			ansl=i;
			ansr=ri[i]+1;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++)a[i+n]=a[i];
	for (int i=1;i<=n;i++)p[i]=(line){a[i],a[i+1]-a[i]};
	for (int i=1;i<=n;i++)push(p[i]);
	h1=h,z0=z2;
	ld ans=2e4;
	for (ld u=2e4;u>eps;u/=2)
		if (check(ans-u))ans-=u;
	check(ans);
	printf("%.12lf\n",ans);
	for (int i=ansl;i<ansr;i++)push(q[i]);
	printf("%.12lf %.12lf\n",z2.x,z2.y);
	clear();
	for (int i=ansr;i<ansl+n;i++)push(q[i]);
	printf("%.12lf %.12lf\n",z2.x,z2.y);	
}