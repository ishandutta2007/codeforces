#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t;
long double res,p=1,lst,d[666],c[666];
priority_queue< pair<long double,int> > q;

int main() {
	scanf("%d",&n);res=n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		d[i]=(100-k)/100.0;c[i]=d[i];
		q.push({(1-d[i]*d[i])/(1-d[i]),i});
		p*=k/100.0;
	}
	for(i=1;i<=500000;i++){
		auto [x,y]=q.top();q.pop();
		res+=1-p;
		p*=x;
		c[y]*=d[y];
		q.push({(1-c[y]*d[y])/(1-c[y]),y});
	}
	printf("%.20Lf",res);
}