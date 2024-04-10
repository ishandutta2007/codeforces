#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,res;
ll f[1005000],sb;

int main(){
	for(i=1;i<=1000000;i++){
		for(j=i;j<=1000000;j+=i){
			f[j]++;
		}
	}
	for(i=1;i<=1000000;i++){
		f[i]+=sb;
		f[i]%=M;
		sb+=f[i];
		sb%=M;
	}
	scanf("%d",&n);
	printf("%lld",f[n]);
}