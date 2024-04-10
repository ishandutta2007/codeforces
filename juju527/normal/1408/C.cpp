#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const double eps=1e-9;
int a[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,l;
		n=read();l=read();
		for(int i=1;i<=n;i++)a[i]=read();
		a[0]=0;a[n+1]=l;
		double t=0;
		int v1=1,v2=1,lf=0,rf=n+1;
		double p1=0,p2=l;
		while(1){
			if(a[lf+1]<=a[rf-1]){
				double t1=1.0*(a[lf+1]-p1)/v1,t2=1.0*(p2-a[rf-1])/v2;
				if(fabs(t1-t2)<=eps){t+=t1;p1=a[++lf];p2=a[--rf];v1++;v2++;}
				else if(t1-t2>eps){t+=t2;p1+=v1*t2;p2=a[--rf];v2++;}
				else{t+=t1;p1=a[++lf];p2-=v2*t1;v1++;}
			}
			else{t+=1.0*(p2-p1)/(v1+v2);break;}
		}
		printf("%.9lf\n",t);
	} 
	return 0;
}