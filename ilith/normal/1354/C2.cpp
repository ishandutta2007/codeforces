#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int t,n;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			printf("1.000000000\n");
		}
		else{
			double p=(n*2-2)*pi/n/2,minus=(pi-p)/2.0,tmp=1;
			int tt;
			if(n&1) tt=n/2; else tt=n/2-1;
			for(int i=1;i<tt;++i) tmp=sqrt(1+tmp*tmp-2*tmp*cos(p)),p-=minus;
			if(n&1) tmp+=sqrt(1+tmp*tmp-2*tmp*cos(p));
			else tmp*=2;
			printf("%.9lf\n",tmp/sqrt(2.0)+(n%2==0));
		}
	}
	return 0;
}