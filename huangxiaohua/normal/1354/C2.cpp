#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pi 3.1415926535897932384626
#define deg(x) (x*pi/180.0)
int i,j,k,n,m,t;
double sb,sb2,l,res;

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		l=0.5/sin(deg(360.0/n/4));
		sb2=360.0/n/8;
		res=2*l*cos(deg(sb2));
		printf("%.20lf\n",res);
	}
}