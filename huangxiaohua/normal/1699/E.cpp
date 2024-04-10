#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[1005000],res,l,r,num[5005000],f[5005000];
bool b[5005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=1e9;l=1e9;r=-1;
		for(i=1;i<=m;i++)b[i]=num[i]=0,f[i]=i;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(!b[a[i]])b[a[i]]=num[a[i]]=1;
			l=min(l,a[i]);r=max(r,a[i]);
		}
		res=r-l;
		for(i=sqrt(m)+1;i>=1;i--){
			for(j=i;j<=m;j+=i){
				if(b[j])num[f[j]]--;
				if(f[j/i]>=i)f[j]=min(f[j/i],f[j]);
				if(b[j])num[f[j]]++;
			}
			while(!num[r])r--;
			res=min(res,r-min(i,l));
		}
		cout<<res<<'\n';
	}
}