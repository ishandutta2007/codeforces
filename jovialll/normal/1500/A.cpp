	#include<bits/stdc++.h>
	using namespace std;
	#define N 5000005
	int T,a[N],i,j,n,uuu,k,x,c[N],p[N],ppp,C[N],fl,u[N],cnt;
	int main(){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],++c[a[i]],++C[a[i]];
		for(i=1;i<N;++i)if(c[i]>3){
			for(j=1;j<=n;++j){
				if(a[j]==i)p[++cnt]=j;
			}
			cout<<"Yes\n"<<p[1]<<" "<<p[2]<<" "<<p[3]<<" "<<p[4]<<"\n";return 0;
		}
		for(i=1;i<N;++i)if(c[i]>1)p[++fl]=i;
		if(fl>1){
			for(i=1;i<=n;++i){
				if(a[i]==p[1])u[++cnt]=i;
				if(cnt==2)break;
			}
			for(i=1;i<=n;++i){
				if(a[i]==p[2])u[++cnt]=i;
			}
			cout<<"Yes\n";
			cout<<u[1]<<' '<<u[3]<<" "<<u[2]<<" "<<u[4]<<"\n";
			return 0;
		}
		ppp=p[1];
		n=min(n,5000);
		for(i=1;i<=n;++i)--c[a[i]];
		for(i=1;i<=n;++i)for(j=1;j<i;++j)++c[a[i]+a[j]];
		for(uuu=1;uuu<N;++uuu){
			if(c[uuu]>1){
				if(ppp>uuu||C[ppp]*C[uuu-ppp]!=c[uuu]){
				cnt=0;
				for(i=1;i<=n;++i)for(j=1;j<i;++j)if(a[i]+a[j]==uuu)p[++cnt]=i,u[cnt]=j;
				for(i=1;i<=cnt;++i){
					for(j=1;j<i;++j){
						if(u[i]!=u[j]&&u[i]!=p[j]&&p[i]!=u[j]&&p[i]!=p[j])return cout<<"Yes\n"<<p[i]<<" "<<u[i]<<" "<<p[j]<<" "<<u[j]<<"\n",0;
					}
				}
				}
			}
		}
		return cout<<"No\n",0;
	}