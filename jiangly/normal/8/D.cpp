#include<bits/stdc++.h>
using namespace std;
namespace two_friends{
	const double eps=1e-12;
	typedef struct Vector{
		double x,y;
		Vector operator-(Vector a){
			return {x-a.x,y-a.y};
		}
		Vector operator+(Vector a){
			return {x+a.x,y+a.y};
		}
		Vector operator*(double a){
			return {x*a,y*a};
		}
		Vector operator/(double a){
			return {x/a,y/a};
		}
		double operator*(Vector a){
			return x*a.x+y*a.y;
		}
		double length(){
			return sqrt((*this)*(*this));
		}
	}point;
	double t1,t2;
	point A,B,C;
	double AB,AC,CB;
	double find_max(double len){
		double l=0.0,r=1.0,mid,ans=0.0;
		for(int i=0;i<100;++i){
			mid=(l+r)/2;
			point U=B+(C-B)*mid;
			point P=(U-A)/(U-A).length()*len+A;
			double u=AB-(P-B).length()+t1,v=AC-(P-C).length()+t2;
			ans=max(ans,min(u,v));
			if(u>v){
				l=mid;
			}else{
				r=mid;
			}
		}
		return ans>len-eps?ans:-1;
	}
	void main(){
		scanf("%lf%lf",&t2,&t1);
		scanf("%lf%lf",&A.x,&A.y);
		scanf("%lf%lf",&B.x,&B.y);
		scanf("%lf%lf",&C.x,&C.y);
		AB=(A-B).length();
		AC=(A-C).length();
		CB=(C-B).length();
		if(AB+t1>=AC+CB){
			printf("%.4lf\n",min(AC+CB+t2,AB+t1));
			return;
		}
		double ans=0.0;
		double l=0.0,r=max(AB,AC),mid;
		for(int i=0;i<100;++i){
			mid=(l+r)/2;
			if(find_max(mid)>0){
				l=mid;
			}else{
				r=mid;
			}
		}
		l=0.0;
		double mid1,mid2;
		while(r-l>eps){
			mid1=(l+r)/2-eps/3;
			mid2=(l+r)/2+eps/3;
			if(find_max(mid1)>find_max(mid2)){
				r=mid2;
			}else{
				l=mid1;
			}
		}
		printf("%.4lf\n",find_max((l+r)/2));
	}
}
int main(){
	two_friends::main();
	return 0;
}