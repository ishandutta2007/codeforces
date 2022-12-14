#include<bits/stdc++.h>
using namespace std;
const double pi=3.1415926535898;
int i,n,t;
double ans,fir,l;
int main(){
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		fir=pi/n/2;l=pi/n;
		for(i=1;i<=n;++i){
			ans+=sin(fir);
			fir+=l;
		}
		printf("%.10lf\n",ans*cos(l/4));
	}
	return 0;
}