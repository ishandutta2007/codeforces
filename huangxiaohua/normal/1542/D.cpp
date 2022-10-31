#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,m,t;
ll n,a[505],f[505][505],res;
string s;

ll chk(ll x,int pos){
	int i,j,k;
	ll res=0;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			f[i][j]+=f[i-1][j];
			if(i==pos){continue;}
			if(i<pos){
				if(a[i]==-1){
					f[i][j]+=f[i-1][j+1];
					if(!j){f[i][j]+=f[i-1][j];}
					f[i][j]%=M;continue;
				}
				if(a[i]<=x){if(j){f[i][j]=(f[i-1][j-1]+f[i][j])%M;}}
				else{f[i][j]=(f[i-1][j]+f[i][j])%M;}
				continue;
			}
			else{
				if(a[i]==-1){f[i][j]=(f[i][j]+f[i-1][j+1])%M;continue;}
				if(a[i]<x){if(j){f[i][j]=(f[i][j]+f[i-1][j-1])%M;}}
				else{f[i][j]=(f[i][j]+f[i-1][j])%M;}
				continue;
			}
		}
	}
	for(i=0;i<=500;i++){res=(res+f[n][i])%M;}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s;
		if(s=="-"){a[i]=-1;}
		else{cin>>a[i];}
	}
	for(i=1;i<=n;i++){
		if(a[i]==-1){continue;}
		res=(res+a[i]*chk(a[i],i))%M;
	}
	cout<<res;
}