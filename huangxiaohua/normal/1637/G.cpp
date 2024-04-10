#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[66666],sb;
vector<pair<int,int> >res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){cout<<"-1\n";continue;}
		for(m=1;m<n;m*=2);
		memset(a,0,m*4+50);
		for(i=1;i<=n;i++)a[i]=1;
		res.clear();
		while(a[m]+a[0]!=n){
			int NMSL=0,nmsl=0;
			for(i=m;i>1;i/=2){
				aa:nmsl=0;
				for(j=1;j<=(i/2);j++){
					k=min(a[j],a[i-j]);
					if(j+j==i)k=a[j]/2;
					NMSL|=k;nmsl|=k;
					a[j]-=k;a[i-j]-=k;
					a[i-j-j]+=k;a[i]+=k;
					while(k--)res.push_back({j,i-j});
				}
				if(nmsl)goto aa;
			}
			if(NMSL)goto aaa;
			for(i=1;i<m;i*=2){
				if(a[i]){
					while(a[i]){
						res.push_back({i,0});
						res.push_back({i,i});
						a[i+i]++;a[i]--;
					}
					break;
				}
			}
			aaa:;
		}
		for(i=1;i<=a[0];i++)res.push_back({m,0});
		cout<<res.size()<<'\n';
		for(auto [x,y]:res)cout<<x<<' '<<y<<'\n';
	}
}