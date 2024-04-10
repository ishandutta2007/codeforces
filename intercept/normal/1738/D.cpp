#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,k;
int a[M],b[M],p[M],s[M];
vector<int>v[M];
void work(){
	cin>>n;
	for(int i=0;i<=n;++i)v[i].clear();
	for(int i=1;i<=n;++i){
		cin>>b[i];
		if(b[i]==0||b[i]==n+1){
			v[0].eb(i);
		}
		else v[b[i]].eb(i);
	}
	for(int i=0;i<=n;++i){
		sort(v[i].begin(),v[i].end(),[&](const int&l,const int&r){return v[l].size()<v[r].size();});
	}
	for(int i=0,m=0;i<=n;++i){
		int x=a[i];
		for(auto o:v[x]){
			a[++m]=o;
		}
	}
	p[0]=n+1;
	s[n+1]=0;
	for(int i=1;i<=n;++i)p[i]=min(p[i-1],b[i]);
	for(int i=n;i>=1;--i)s[i]=max(s[i+1],b[i]);
	for(int i=0;i<=n;++i){
		if(p[i]>i&&s[i+1]<=i){
			cout<<i<<"\n";
		}
	}
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 1
4
*/