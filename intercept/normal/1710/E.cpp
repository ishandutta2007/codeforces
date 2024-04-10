#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m,pa,pb;
int a[M],b[M],id[M];
int ca[M],cb[M];
bool check(int z){
	if(a[pa]+b[pb]<=z)return 1;
	ll rex=0,a1=0,a2=0;
	for(int i=1,j=m;i<=n;++i){
		while(j&&a[i]+b[j]>z)j--;
		rex+=m-j;
	}
	a1=rex;
	int x=n,y=m;
	while(x&&a[x]+b[1]>z)x--;
	for(int i=1,j=0;i<=n;++i){
		while(y&&a[i]+b[y]>z)y--;
		rex+=j+y-m;
		while(j<m&&i+x-n>=0){
			rex+=i+x-n;
			j++;
			while(x&&a[x]+b[j+1]>z)x--;
		}
		a1=max(a1,rex);
		if(i>=pa||j>=pb)a2=max(a2,rex);
	}
	return a1==a2;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	int aa=a[1],bb=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	pa=lower_bound(a+1,a+n+1,aa)-a;
	pb=lower_bound(b+1,b+m+1,bb)-b;
	int l=2,r=1e9;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}
/*
4 4
4 3 2 4
4 3 2 4
10 10
100 3 6 2 4 7 12 3 4 6 
10 3 2 2 7 12 3 4 6 8
*/