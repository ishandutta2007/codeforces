#include<bits/stdc++.h>
using namespace std;
const double pi=3.1415926535898;
int i,n,t;
double ans,fir,l;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		n>>=1;
		ans=-0.5;
		fir=0;l=pi/n/2;
		for(i=1;i<=n;++i){
			fir+=l;
			ans+=sin(fir);
		}
		printf("%.10lf\n",ans*2);
	}
	return 0;
}