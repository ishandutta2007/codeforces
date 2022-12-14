#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define mod 998244353
#define pb push_back
int T,n,m,i,j,k,x,y,a[N],pos[N];
ll u,rr;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;u=x=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]&1)pos[++x]=i;
		}
		if(n&1){
			if(x==(n>>1)){
				for(i=1;i<=x;++i)u+=abs(i*2-pos[i]);
			}
			else if(x==(n>>1)+1){
				for(i=1;i<=x;++i)u+=abs(i*2-1-pos[i]);
			}
			else u=-1;
		}
		else {
			if(x==(n>>1)){
				rr=0;
				for(i=1;i<=x;++i)u+=abs(i*2-pos[i]);
				for(i=1;i<=x;++i)rr+=abs(i*2-1-pos[i]);
				u=min(u,rr);
			}
			else u=-1;
		}
		cout<<u<<"\n";
	}
	return 0;
}