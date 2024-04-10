#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[300500],f[300500];
ll res;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		map<int,int> mp;
		map<int,vector<int> >mp2;
		map<pair<int,int>,bool> sb;
		for(i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]++;
			f[i]=0;
		}
		for(auto [i,j]:mp){
			mp2[j].push_back(i);
		}
		for(auto &[i,j]:mp2){
			sort(j.begin(),j.end());
			reverse(j.begin(),j.end());
		}
		for(i=1;i<=m;i++){
			cin>>j>>k;
			sb[{j,k}]=1;
		}
		for(auto &[i,v1]:mp2){
			for(auto &x:v1){
				for(auto &[j,v2]:mp2){
					if(j>i)break;
					for(auto &y:v2){
						if(x==y)continue;
						if(sb.count(make_pair(min(x,y),max(x,y))))continue;
						f[i+j]=max(f[i+j],x+y);
						break;
					}
				}
			}
		}
		res=0;
		for(i=1;i<=n;i++){
			res=max(res,1ll*i*f[i]);
		}
		cout<<res<<'\n';
	}
}