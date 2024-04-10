#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n,k;
int a[M],b[M];
bool check(int x){
	int t=0;
	for(int i=1;i<=n;++i){
		b[i]=a[i];
		if(b[i]*2<x)b[i]=1e9,t++;
	}
	int flag=1,bol=1;
	for(int i=2;i<=n;++i){
		if(min(b[i],b[i-1])>=x)flag=0;
		if(max(b[i],b[i-1])>=x)bol=0;
	}
	t+=flag+bol;
	return t<=k;
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=1,r=1e9;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid+1))l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
2 1
5 9
*/