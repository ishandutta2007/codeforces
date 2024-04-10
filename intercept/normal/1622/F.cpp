#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e6+9;
int n;
bool vis[M];
ll a[M],b[M];
mt19937_64 rd(time(0));
map<ll,int>mp;
int main(){
	cin>>n;
	if(n==1){
		puts("1");
		puts("1");
		return 0;
	}
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			ll x=rd();
			for(ll k=i;k<=n;k*=i){
				for(int j=k;j<=n;j+=k){
					a[j]^=x;
				}
			}
			for(int j=i+i;j<=n;j+=i)vis[j]=1;
		}
	}
	for(int i=2;i<=n;++i){
		a[i]^=a[i-1];
		mp[a[i]]=i;
	}
	for(int i=2;i<=n;++i){
		b[i]=b[i-1]^a[i];
	}
	if(b[n]==0){
		printf("%d\n",n);
		for(int i=1;i<=n;++i){
			printf("%d ",i);
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==b[n]){
			printf("%d\n",n-1);
			for(int j=1;j<=n;++j){
				if(j==i)continue;
				printf("%d ",j);
			}
			return 0;
		}
	}
	for(int i=1;i<=n;++i){
		if(mp.count(b[n]^a[i])){
			int x=i,y=mp[b[n]^a[i]];
			printf("%d\n",n-2);
			for(int j=1;j<=n;++j){
				if(j==x||j==y)continue;
				printf("%d ",j);
			}
			return 0;
		}
	}
	printf("%d\n",n-3);
	for(int j=1;j<=n;++j){
		if(j==n||j==n/2||j==2)continue;
		printf("%d ",j);
	}
	return 0;
}
/*
*/