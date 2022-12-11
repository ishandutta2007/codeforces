#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x,y;
	void scan(){
		scanf("%d%d",&x,&y);
	}
}P,A[110000];
#define sqr(x) ((x)*(x))
long long dis(point k1,point k2){
	return sqr(1ll*k1.x-k2.x)+sqr(1ll*k1.y-k2.y);
}
int n;
double mi,ma;
const double pi=acos(-1);
point operator - (point k1,point k2){
	return (point){k1.x-k2.x,k1.y-k2.y};
}
long long cross(point k1,point k2){
	return 1ll*k1.x*k2.y-1ll*k2.x*k1.y;
}
long long dot(point k1,point k2){
	return 1ll*k1.x*k2.x+1ll*k1.y*k2.y;
}
int main(){
	scanf("%d",&n); P.scan(); ma=0,mi=1e18;
	for (int i=1;i<=n;i++) A[i].scan();
	for (int i=1;i<=n;i++) ma=max(ma,(double)dis(A[i],P));
	A[n+1]=A[1];
	for (int i=1;i<=n;i++){
	//	cout<<dot(A[i+1]-A[i],P-A[i])<<" "<<dot(A[i]-A[i+1],P-A[i+1])<<endl;
		if (dot(A[i+1]-A[i],P-A[i])>=0&&dot(A[i]-A[i+1],P-A[i+1])>=0) mi=min(mi,sqr(cross(A[i]-P,A[i+1]-P)/sqrt(dis(A[i],A[i+1]))));
		else mi=min(mi,(double)min(dis(P,A[i]),dis(P,A[i+1])));
	}
//	cout<<ma<<" "<<mi<<endl;
	printf("%.11lf\n",(ma-mi)*pi);
	return 0;
}