#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n=readint();
	double p;
	scanf("%lf",&p);
	int l=0,r=n;
	while(l<r){
		int mid=l+(r-l)/2;
		auto C2=[](int n){
			return n>=2?n*(n-1)/2:0;
		};
		auto C3=[](int n){
			return n>=3?n*(n-1)*(n-2)/6:0;
		};
		double res=0;
		res+=0.5*mid*C2(n-mid)/C3(n);
		res+=1.0*C2(mid)*(n-mid)/C3(n);
		res+=1.0*C3(mid)/C3(n);
		if(res>=p) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}