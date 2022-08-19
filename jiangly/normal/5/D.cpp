//Time Complexity : O(1)
//Space Complexity : O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,v,l,d,w;
	scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
	w=min(w,v);
	if(2.0*a*d<=w*w){
		if(2.0*a*l<=v*v){
			printf("%lf\n",sqrt(2.0*l/a));
		}else{
			double t=v/a;
			l=l-0.5*a*t*t;
			t=t+l/v;
			printf("%lf\n",t);
		}
	}else{
		double t=0.0;
		l=l-d;
		if(2.0*a*d>=2.0*v*v-w*w){
			d=d-0.5*(2.0*v*v-w*w)/a;
			t=(2.0*v-w)/a+d/v;
		}else{
			double d1=d+0.5*w*w/a;
			d1=d1*0.5;
			d=d-d1;
			double t1=sqrt(2.0*d1/a),t2=(-w+sqrt(w*w+2.0*a*d))/a;
			t=t1+t2;
		}
		if(2.0*a*l<=v*v-w*w){
			t=t+(-w+sqrt(w*w+2.0*a*l))/a;
			printf("%lf\n",t);
		}else{
			t=t+(v-w)/a;
			l=l-0.5*(v*v-w*w)/a;
			t=t+l/v;
			printf("%lf\n",t);
		}
	}
	return 0;
}