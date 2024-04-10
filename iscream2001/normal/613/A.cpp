#include<bits/stdc++.h>
#define double long double
#define LL long long
using namespace std;
const LL INF=1e18;
const double PI=acos(-1.0);
inline char gc(){return getchar();}
inline int read(){
    int f=1,c; 
	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
	int x=c-'0';
    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
	return f>0?x:-x;
}
int n;
struct P{
	double x,y;
	P(double _x=0,double _y=0){
		x=_x;y=_y;
	}
}a[100005],O;
P operator + (P x,P y){
	return P(x.x+y.x,x.y+y.y);
}
P operator - (P x,P y){
	return P(x.x-y.x,x.y-y.y);
}
double  operator * (P x,P y){
	return x.x*y.x+x.y*y.y;
}
double  operator / (P x,P y){
	return x.x*y.y-x.y*y.x;
}
double dis(P x){
	return sqrt(x.x*x.x+x.y*x.y);
}
P Point_On_Line(P O,P x,P y){
	P re=y-x;
	double w=dis(re);
	//cout<<w<<endl;
	re.x/=w;re.y/=w;
	double L=(O-x)*re;
	//cout<<L<<endl;
	re.x*=L;re.y*=L;
	return x+re;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();O.x=read();O.y=read();
	double mn=INF,mx=0,w;
	for(int i=1;i<=n;++i){
		a[i].x=read();a[i].y=read();
		a[i]=a[i]-O;
		w=dis(a[i]);
		mn=min(mn,w);
		mx=max(mx,w);
	}
	a[n+1]=a[1];O.x=0;O.y=0;
	P tmp;
	for(int i=1;i<=n;++i){
		tmp=Point_On_Line(O,a[i],a[i+1]);
		if(tmp.x>=min(a[i].x,a[i+1].x)
		&&tmp.x<=max(a[i].x,a[i+1].x)
		&&tmp.y>=min(a[i].y,a[i+1].y)
		&&tmp.y<=max(a[i].y,a[i+1].y)){
	//		cout<<i<<" "<<tmp.x<<" "<<tmp.y<<endl;
			w=dis(tmp);
			mn=min(mn,w);
		}
	}
	//cout<<mn<<endl;
	printf("%0.18Lf\n",PI*(mx*mx-mn*mn));
	return 0;
}