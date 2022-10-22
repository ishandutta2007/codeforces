#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
const int B=209;
int n,q;
int a[M];
int vis[M];
ll sum[M];
int id(int i){
	return (i-1)/B+1;
}
int L(int i){
	return (i-1)*B+1;
}
int R(int i){
	return min(i*B,n);
}
void change(int x){
	if(vis[x]==0)return;
	sum[x]=0;
	for(int i=L(x);i<=R(x);++i)a[i]=max(a[i],vis[x]),sum[x]+=a[i];
	vis[x]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		sum[id(i)]+=a[i];
	}
	for(int t=1;t<=q;++t){
		int o,x,y;
		cin>>o>>x>>y;
		if(o==1){
			change(id(x));
			for(int i=L(id(x));i<=x;++i){
				sum[id(i)]-=a[i];
				a[i]=max(a[i],y);
				sum[id(i)]+=a[i];
			}
			for(int i=1;i<id(x);++i){
				if(max(a[R(i)],vis[i])>=y)continue;
				if(max(a[L(i)],vis[i])<=y){
					vis[i]=y;
					sum[i]=1ll*(R(i)-L(i)+1)*y;
					continue;
				}
				change(i);
				vis[i]=y;
				change(i);
			}
		}
		else{
			change(id(x));
			int ans=0;
			for(int i=x;i<=R(id(x));++i){
				if(y>=a[i])y-=a[i],ans++;
			}
			for(int i=id(x)+1;i<=id(n);++i){
				if(y>=sum[i]){
					y-=sum[i];
					ans+=R(i)-L(i)+1;
				}
				else if(y>=max(a[R(i)],vis[i])){
					change(i);
					for(int j=L(i);j<=R(i);++j){
						if(y>=a[j])y-=a[j],ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
10 2
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
*/