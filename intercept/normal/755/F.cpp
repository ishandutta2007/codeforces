#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n,k;
int a[M],vis[M],p[M],cnt[M];
bitset<M>dp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	int p1;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int x=i,num=1;
			vis[x]=1;
			x=p[x];
			while(x!=i){
				num++;
				vis[x]=1;
				x=p[x];
			}
			cnt[num]++;
			if(num&1)p1++;
		}
	}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		int x=cnt[i];
		for(int y=1;x;x-=y,y=min(y*2,x))dp|=dp<<(y*i);
	}
	cout<<k+(dp[k]==0)<<" "<<min((n-p1)/2,k)*2+min(p1,k-min((n-p1)/2,k))<<"\n";
	return 0;
}