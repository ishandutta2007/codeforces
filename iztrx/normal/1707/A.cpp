#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 998244353
int a[N],b[N],las[N],q,t,n,i,cnt[N];
map<int,int>p;
bool check(int v){
	int qq=q;
	for(i=v;i<=n;++i){
		if(a[i]>qq)--qq;
	}
	return qq>=0;
}
void print(int v){
	for(i=1;i<v;++i)if(a[i]<=q)cout<<1;else cout<<0;
	for(;i<=n;++i){
		cout<<1;
	}cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
		sort(b+1,b+n+1);
		for(i=1;i<=n;++i){
			if(b[i]==b[i-1])las[i]=las[i-1];
			else las[i]=i;
		}p.clear();
		for(i=n;i;--i){
			++p[a[i]];
			cnt[i]=p[a[i]];
		}
		int l=1,r=n,mid;
		while(l<r){
			mid=(r+l>>1);
			if(check(mid))r=mid;
			else l=mid+1;
		}
		print(l);
	}
}