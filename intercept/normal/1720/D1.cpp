#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+9;
int n,sz;
int a[M],b[M],c[M*31][2],p[M*31][2][2];
void work(){
	sz=0;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i],b[i]=a[i]^i;
	for(int i=0;i<n;++i){
		int u=0,s=1;
		for(int j=30;j>=0;--j){
			if(b[i]>>j&1){
				if(a[i]>>j&1)s=max(s,p[u][0][0]+1);
				else s=max(s,p[u][0][1]+1);
			}
			else{
				if(a[i]>>j&1)s=max(s,p[u][1][0]+1);
				else s=max(s,p[u][1][1]+1);
			}
			if(!c[u][b[i]>>j&1])c[u][b[i]>>j&1]=++sz;
			u=c[u][b[i]>>j&1];
		}
		u=0;
		for(int j=30;j>=0;--j){
			p[u][b[i]>>j&1][i>>j&1]=max(p[u][b[i]>>j&1][i>>j&1],s);
			u=c[u][b[i]>>j&1];
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	for(int i=0;i<=sz;++i)c[i][0]=c[i][1]=p[i][0][0]=p[i][0][1]=p[i][1][0]=p[i][1][1]=0;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
2
1 2
*/