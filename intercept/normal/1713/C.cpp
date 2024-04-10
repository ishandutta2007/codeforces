#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int a[M];
void dfs(int n){
	if(n<0)return;
	int t=0;
	while(t*t<n)t++;
	for(int i=n,j=t*t-n;j<=n;i--,j++){
		a[i]=j;
	}
	dfs(t*t-n-1);
}
void work(){
	int n;
	cin>>n;
	dfs(n-1);
	for(int i=0;i<n;++i)cout<<a[i]<<" ";
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}