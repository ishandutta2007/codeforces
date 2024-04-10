#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,vis[10050],it,p[10050];
string s,s2,s3;
ll res,sb;

int main(void) {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--) {
		cin>>n>>s;
		s="X"+s;s2=s3=s;
		for(i=1;i<=n;i++){cin>>p[i];vis[i]=0;}
		m=0;res=1;
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			j=i;
			vector<int> tmp;
			while(!vis[j]){tmp.push_back(j);vis[j]=1;j=p[j];}
			for(j=1;;j++){
				for(auto k:tmp)s3[k]=s2[p[k]];
				for(auto k:tmp)s2[k]=s3[k];
				for(auto k:tmp)if(s[k]!=s2[k])goto aaa;
				sb=j;break;
				aaa:;
			}
			res=res/__gcd(res,sb)*sb;
		}
		cout<<res<<'\n';
	}
}