#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[1050],g[1050],t1,h[1050],nmsl[1050],res[1050],st;

int ask(){
	int j,k=0;
	t++;
	if(t>675)while(1);
	for(j=1;j<=n;j++){cout<<"FT"[f[j]];}cout<<endl;
	cin>>k;
	if(k==n)exit(0);
	return k;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n/2;i++){
		res[i]=1;
	}
	for(i=1;i<=n;i++){
		g[i]=i;
	}
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	shuffle(g+1,g+n+1,rng);
	k=ask();
	st=1;
	for(i=2;i<=n;i++){
		f[g[i]]^=1;
		f[g[i-1]]^=1;
		t1=ask();
		if(t1==k-2){
			f[g[i]]^=1;
			f[g[i-1]]^=1;
			for(j=i-2;j>=st;j-=1){
				f[g[j]]^=1;k++;
			}
			st=i+1;i++;
		}
		else if(t1==k+2){
			k+=2;
			st=i+1;i++;
		}
	}
	f[g[n]]^=1;
	t1=ask();
	if(t1<k){
		f[g[n]]^=1;
		for(j=n-1;j>=st;j-=1)f[g[j]]^=1;
	}
	ask();
	return 1;
}///////