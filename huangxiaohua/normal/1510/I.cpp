#include <bits/stdc++.h>
using namespace std;
int i,j,k,k2,n,m,t,b[1050],yes[10500];
char nmsl[1050];
double k0,k1,sb,wt[1050];

int main() {
	ios::sync_with_stdio(0);
	default_random_engine e(time(0));
	cin>>n>>t;
	for(i=1;i<=n;i++){wt[i]=10;}
	while(t--){
		cin>>nmsl+1;
		for(i=1;i<=n;i++){
			b[i]=nmsl[i]-'0';
		}
		k0=k1=0;
		for(i=1;i<=n;i++){
			if(b[i]==0){k0+=wt[i];}
			else{k1+=wt[i];}
		}
		uniform_real_distribution<double> u(0,k0+k1);
		sb=u(e);
		if(sb<=k0){cout<<0<<'\n';fflush(stdout);}
		else{cout<<1<<'\n';fflush(stdout);}
		aaa:cin>>k;
		for(i=1;i<=n;i++){
			if(k!=b[i]){
				wt[i]*=0.9;
			}
		}
	}
}