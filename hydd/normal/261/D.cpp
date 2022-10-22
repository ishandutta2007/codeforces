#include<bits/stdc++.h>
using namespace std;
int k,n,m,t,a[110000],c[110000];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>k>>n>>m>>t; t=min(t,m);
	while (k--){
		for (int i=1;i<=m;i++) c[i]=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=t;i++)
			for (int j=1;j<=n;j++){
				int pos=a[j],v=c[pos-1]+1;
				while (pos<=m&&c[pos]<v) c[pos++]=v;
			}
		cout<<c[m]<<endl;
	}
	return 0;
}