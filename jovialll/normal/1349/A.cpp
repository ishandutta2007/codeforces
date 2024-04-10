	#include<bits/stdc++.h>
	using namespace std;
	#define N 500005
	#define int long long
	int T,i,a[N],p[N],is[N],j,n,cnt,k1,k2,res,ans=1;
	signed main(){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		for(i=2;i<N;++i){
			if(!is[i])p[++cnt]=i;
			for(j=i+i;j<N;j+=i)is[j]=1;
		}
		for(i=1;i<=cnt;++i){
			if(a[1]%p[i]==0||a[2]%p[i]==0){
				k1=9999,k2=9999;
				for(j=1;j<=n;++j){
					res=0;
					while(a[j]%p[i]==0){
						a[j]/=p[i];
						++res;
					}
					if(res<k1)k2=k1,k1=res;
					else if(k2>res)k2=res;
				}
				for(j=1;j<=max(k1,k2);++j){
					ans*=p[i];
				}
			}
		}cout<<ans;return 0;
	}