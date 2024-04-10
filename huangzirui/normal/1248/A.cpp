#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll ji1=0,ou1=0,ji2=0,ou2=0;
		read(n);
		for(i=1;i<=n;i++){ll x;read(x);if(x&1)ji1++;else ou1++;}
		read(m);
		for(i=1;i<=m;i++){ll x;read(x);if(x&1)ji2++;else ou2++;}
		cout<<ji1*ji2+ou1*ou2<<endl;
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}