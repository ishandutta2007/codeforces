#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[10005],cnt,b[10005],u[105],uu,i,j;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;cnt=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(!b[a[i]])b[a[i]]=1,++cnt;
		}
		if(cnt>k){cout<<-1<<"\n";continue;}
		u[1]=a[1];uu=1;
		for(i=1;i<=n;++i){
			if(b[i]&&a[1]!=i)u[++uu]=i;
		}
		for(i=uu+1;i<=k;++i)u[i]=a[1];
		cout<<n*k<<"\n";
		for(i=1;i<=n;++i){
			for(j=1;j<=k;++j){
				cout<<u[j]<<" ";
			}
		}
	}
	return 0;
}