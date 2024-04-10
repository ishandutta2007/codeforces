//Time Complexity : O(1)
//Space Complexity : O(1)
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-12;
struct circle{
	double x,y,r;
}A,B,C;
struct equation{
	double a,b,c,d;
	double operator()(double x,double y){
		return a*x*x+a*y*y+b*x+c*y+d;
	}
};
equation geteq(circle A,circle B){
	return {A.r*A.r-B.r*B.r,2*(B.r*B.r*A.x-A.r*A.r*B.x),2*(B.r*B.r*A.y-A.r*A.r*B.y),A.r*A.r*(B.x*B.x+B.y*B.y)-B.r*B.r*(A.x*A.x+A.y*A.y)};
}
vector<pair<double,double>>solve(equation F,equation G){
	if(fabs(F.a)<eps&&fabs(G.a)<eps){
		if(fabs(F.b)<eps){
			swap(F,G);
		}
		F.c=F.c/F.b;
		F.d=F.d/F.b;
		F.b=1.0;
		G.c=G.c-G.b*F.c;
		G.d=G.d-G.b*F.d;
		G.b=0.0;
		G.d=G.d/G.c;
		G.c=1.0;
		F.d=F.d-F.c*G.d;
		F.c=0.0;
		return {{-F.d,-G.d}};
	}
	if(fabs(F.a)<eps){
		swap(F,G);
	}
	F.b=F.b/F.a;
	F.c=F.c/F.a;
	F.d=F.d/F.a;
	F.a=1.0;
	G.b=G.b-G.a*F.b;
	G.c=G.c-G.a*F.c;
	G.d=G.d-G.a*F.d;
	G.a=0.0;
	if(fabs(G.b)<eps){
		G.d=G.d/G.c;
		G.c=1.0;
		F.d=F.d-G.d*(F.c+G.d);
		if(F.b*F.b-4.0*F.a*F.d<-eps){
			return {};
		}
		double x1=(-F.b-sqrt(F.b*F.b-4.0*F.a*F.d))*0.5,x2=(-F.b+sqrt(F.b*F.b-4.0*F.a*F.d))*0.5;
		return {{x1,-G.d},{x2,-G.d}};
	}
	G.c=G.c/G.b;
	G.d=G.d/G.b;
	G.b=1.0;
	F.a=1.0+G.c*G.c;
	F.c=F.c+G.c*(2*G.d-F.b);
	F.d=F.d+G.d*(G.d-F.b);
	F.b=0.0;
	if(F.c*F.c-4.0*F.a*F.d<-eps){
		return {};
	}
	double y1=(-F.c-sqrt(F.c*F.c-4.0*F.a*F.d))*0.5/F.a,y2=(-F.c+sqrt(F.c*F.c-4.0*F.a*F.d))*0.5/F.a;
	return {{-G.c*y1-G.d,y1},{-G.c*y2-G.d,y2}};
}
int main(){
	scanf("%lf%lf%lf",&A.x,&A.y,&A.r);
	scanf("%lf%lf%lf",&B.x,&B.y,&B.r);
	scanf("%lf%lf%lf",&C.x,&C.y,&C.r);
	equation P=geteq(A,B),Q=geteq(B,C),R=geteq(C,A);
	auto U=solve(P,Q),V=solve(Q,R),W=solve(R,P);
	vector<pair<double,double>>ans;
	for(auto i:U){
		bool f=0;
		for(auto j:V){
			if(fabs(i.first-j.first)<eps&&fabs(i.second-j.second)<eps){
				f=1;
				break;
			}
		}
		if(!f){
			continue;
		}
		f=0;
		for(auto j:W){
			if(fabs(i.first-j.first)<eps&&fabs(i.second-j.second)<eps){
				f=1;
				break;
			}
		}
		if(!f){
			continue;
		}
		ans.push_back({i.first,i.second});
	}
	if(ans.empty()){
		return 0;
	}
	auto p=ans[0];
	for(auto q:ans){
		if((q.first-A.x)*(q.first-A.x)+(q.second-A.y)*(q.second-A.y)<(p.first-A.x)*(p.first-A.x)+(p.second-A.y)*(p.second-A.y)){
			p=q;
		}
	}
	printf("%.5lf %.5lf\n",p.first+eps,p.second+eps);
	return 0;
}