#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,k,m[N],c[N],b[N],ans,f,siz,i,j;
vector < int > ANS[N];
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>m[i],++c[m[i]];
	for(i=k;i;--i)c[i]+=c[i+1];
	for(i=1;i<=k;++i)cin>>b[i];
	for(i=1;i<=k;++i)ans=max(ans,(c[i]+b[i]-1)/b[i]); 
	sort(m+1,m+n+1);
	f=1;
	cout<<ans<<"\n";
	for(i=n;i;--i){
		ANS[f].push_back(m[i]);
		f=f%ans+1;
	}
	for(i=1;i<=ans;++i){
		siz=ANS[i].size();
		cout<<siz<<" ";
		for(j=0;j<siz;++j){
			cout<<ANS[i][j]<<" ";
		}cout<<"\n";
	}
	return 0;
}