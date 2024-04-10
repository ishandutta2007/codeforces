#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m=20000000;

int i,j,k,n,t;
ll a[20005000],f[20005000],res;
bool vis[20050000];

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j*j<=k;j++){
			if(!(k%j)){
				a[j]++;
				if((j*j)!=k)a[k/j]++;
				vis[j]=vis[k/j]=1;
			}
		}
	}
	for(i=m;i>=1;i--){
		if(!vis[i])continue;
		f[i]=a[i]*i;
		for(j=i;j<=m;j+=i){
			if(!vis[j])continue;
			f[i]=max(f[i],(a[i]-a[j])*i+f[j]);
		}
		res=max(res,f[i]);
	}//
	cout<<res;
}