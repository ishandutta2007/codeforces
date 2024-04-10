#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,q;
int a[M],id[M];
bool vis[M];
int ans;
bool check(int p){
	ans=0;
	int qq=q;
	for(int i=p;i<=n;++i){
		if(qq){
			if(a[i]>qq)qq--;
		}
		if(qq==0)return i==n;
	}
	return 1;
}
void work(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	for(int i=1;i<l;++i){
		if(a[i]<=q)putchar('1');
		else putchar('0');
	}
	for(int i=l;i<=n;++i){
		if(q){
			if(a[i]>q)q--;
			putchar('1');
		}
		else putchar('0');
	}
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5 2
5 1 2 4 3

*/