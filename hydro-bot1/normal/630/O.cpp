// Hydro submission #631f3244bdf9bc31d15c87d5@1662988869381
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int px,py,vx,vy;double a,b,c,d,p;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	p=sqrt(vx*vx+vy*vy);
    a/=p*2,b/=p,c/=p*2,d/=p;
	printf("%.12lf %.12lf\n",px+b*vx,py+b*vy);
	printf("%.12lf %.12lf\n",px-vy*a,py+vx*a);
	printf("%.12lf %.12lf\n",px-vy*c,py+vx*c);
	printf("%.12lf %.12lf\n",px-vy*c-vx*d,py+vx*c-vy*d);
	printf("%.12lf %.12lf\n",px+vy*c-vx*d,py-vx*c-vy*d);
	printf("%.12lf %.12lf\n",px+vy*c,py-vx*c);
	printf("%.12lf %.12lf\n",px+vy*a,py-vx*a);
	return 0;
}