#include <cstdio>
#include <cmath>

int n,x[100001],y[100001];
inline int add(int a,const int &b){a+=b;return(a>=n)?a-n:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+n:a;}
double ans;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
long long abs(long long x){return x<0?-x:x;}
struct vector{
	int x,y;
	vector operator-(vector a){return (vector){x-a.x,y-a.y};}
	long long operator*(vector a){return (1ll*x*a.y)-(1ll*y*a.x);}
}nod[100001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&nod[i].x,&nod[i].y);
	for(int i=2;i<n;i++){
		ans+=abs((nod[i]-nod[i-1])*(nod[i]-nod[0]));
	}
	for(int i=0;i<n;i++){
		long double S=0.;
		for(int j=1;j<=50&&j<n;j++){
//			S=0.;
			if(j>1)S+=abs((nod[i]-nod[sub(i,j)])*(nod[i]-nod[sub(i,j-1)]));
			long double temp=S;
			temp+=gcd(abs(nod[i].x-nod[sub(i,j)].x),abs(nod[i].y-nod[sub(i,j)].y));
			if(n>50)ans-=temp*std::pow((long double)0.5,j+1);
			else ans-=temp*(std::pow((long double)2.0,n-j-1)-1.0)/(std::pow((long double)2.0,n)-1.0-(long double)n-(long double)(n*(n-1))*0.5);
		}
	}
	ans/=2.0;
	ans+=1.0;
	printf("%.10lf",ans);
}