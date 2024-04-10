#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
int a[1000010];
int main() {
	cin>>n;
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+1+n);
	ll s1=0,s2=0;
	for(i=1;i<=n/2;i++)s1+=a[i];
	for(i=n/2+1;i<=n;i++)s2+=a[i];
	cout<<s1*s1+s2*s2<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}