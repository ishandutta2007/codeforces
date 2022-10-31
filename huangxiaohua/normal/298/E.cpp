#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,r1[200500],r2[200500];
struct SB{
	int id,w;
	bool operator<(const SB x)const{return w<x.w;}
}s[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	m=(n+2)/3;
	for(i=1;i<=n;i++){
		cin>>s[i].w;
		s[i].id=i;
	}
	sort(s+1,s+n+1);
	for(i=1;i<=m;i++){
		int x=s[i].id,y=s[i].w;
		r1[x]=i-1;
		r2[x]=y-i+1;
	}
	for(i=m+1;i<=m+m;i++){
		int x=s[i].id,y=s[i].w;
		r1[x]=0;
		r2[x]=y;
	}
	for(i=m+m+1;i<=n;i++){
		int x=s[i].id,y=s[i].w,z=s[m*3+1-i].w;
		r1[x]=y-z;
		r2[x]=z;
	}
	cout<<"YES\n";
	for(i=1;i<=n;i++)cout<<r1[i]<<' ';
	cout<<endl;
	for(i=1;i<=n;i++)cout<<r2[i]<<' ';
}