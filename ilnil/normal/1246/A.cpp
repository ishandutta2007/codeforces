#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int N=1e6+5,mo=1e9+7,mo2=998244353;
int n,p;
int ans;
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	cin>>n>>p;
	int nn=0;
	fo(i,1,100){
		nn=n-i*p;
		if(nn<0)break;
		if(nn>=i&&__builtin_popcount(nn)<=i){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1");
}