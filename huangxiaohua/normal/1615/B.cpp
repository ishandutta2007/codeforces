#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500][22],res;
#define b(x) (1<<((x)-1))

int main(){
	ios::sync_with_stdio(0);
	for(i=1;i<=200000;i++){
		for(j=1;j<=20;j++){
			f[i][j]=f[i-1][j];
			if(b(j)&i){
				f[i][j]++;
			}
		}
	}
	cin>>t;
	while(t--){
		cin>>j>>k;
		res=0;
		for(i=1;i<=20;i++){
			res=max(res,f[k][i]-f[j-1][i]);
		}
		cout<<k-j+1-res<<'\n';
	}
}