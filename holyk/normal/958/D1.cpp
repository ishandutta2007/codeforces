#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
typedef long long ll;
inline int read(){
	int w=0;char c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))w=w*10+c-48,c=getchar();
	return w;
}
int n;
double x[2000007];
#define eps 1e-7
map<double,int>p;
int main(){
	n=read();
	REP(i,1,n){
		int a=read(),b=read(),c=read();
		x[i]=(double)(a+b)/c;
		auto t=p.lower_bound(x[i]-eps);
		if(t==p.end()||t->first>x[i]+eps)++p[x[i]];
		else t->second++; 
	}
	REP(i,1,n){
		auto t=p.lower_bound(x[i]-eps);
		printf("%d ",t->second);
	}
	return 0;
}