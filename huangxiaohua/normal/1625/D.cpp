#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define go(x) {if(x){cur=x;}else break;}
#define ans(x) {res.push_back(j);res.push_back(id[x]);goto aaa;}
int i,j,k,n,t,l[10005000],r[10005000],it,id[10005000],cur,b[666],kk;
int m,sb;
map<int,vector<pair<int,int> > >mp;
vector<pair<int,int> > t1,t0;
vector<int> res;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=30;i>=1;i--){
		b[i]=(b(i)&m);
	}
	if(!m){
		cout<<n<<endl;
		for(i=1;i<=n;i++)cout<<i<<' ';
		return 0;
	}
	for(sb=1;sb<=m;sb<<=1);
	for(i=1;i<=n;i++){
		cin>>k;
		mp[k/sb].push_back({k,i});
	}
	sb/=2;
	for(auto [lj,v]:mp){
		t1.clear();
		it=0;kk=0;
		for(auto [i,j]:v){
			if(i&sb)t1.push_back({i,j});
			else{
				cur=0;
				kk=j;
				for(k=31;k>=1;k--){
					if(i&b(k)){
						if(!r[cur])r[cur]=++it;
						cur=r[cur];
					}
					else{
						if(!l[cur])l[cur]=++it;
						cur=l[cur];
					}
					id[cur]=j;
				}
			}
		}
		for(auto [i,j]:t1){
			cur=0;
			for(k=31;k>=1;k--){
				if(b[k]){
					if(i&b(k))go(l[cur])
					else go(r[cur])
				}
				else{
					if(i&b(k)){
						if(l[cur])ans(l[cur])
						else go(r[cur])
					}
					else{
						if(r[cur])ans(r[cur])
						else go(l[cur])
					}
				}
			}
			if(!k&&id[cur])ans(cur)
		}
		if(t1.size()){res.push_back(t1[0].second);}
		else if(kk)res.push_back(kk);
		aaa:;
		while(it>=0){l[it]=r[it]=id[it]=0;it--;}
	}
	if(res.size()<=1)cout<<-1;
	else{
		cout<<res.size()<<'\n';
		for(auto i:res)cout<<i<<' ';
	}
}