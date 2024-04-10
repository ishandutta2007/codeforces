#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 

int i,j,k,n,m,t,mx,it,v[2050];
vector<ll> f[2050];
multiset<ll> s[2050];
ll a[200500];
vector<int> NMSL;

void get(){
	ll res=0;
	for(int i=1;i<=it;i++){
		res=max(res,*(--s[i].end()));
	}
	cout<<res<<'\n';
}

int main() {
	for(i=2;i<=200000;i++){
		if(!a[i]){
			NMSL.push_back(i);
			for(j=i;j<=200000;j+=i)a[j]=1;
		}
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		it=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(auto i:NMSL){
			if(i>n)break;
			if(n%i)continue;
			i=n/i;
			v[++it]=i;
			f[it]=vector<ll>(i+1,0);
			for(j=1;j<=i;j++){
				for(k=j;k<=n;k+=i){
					f[it][j]+=a[k]*i;
				}
				s[it].insert(f[it][j]);
			}
		}
		get();
		while(m--){
			int x,y;
			cin>>x>>y;
			for(i=1;i<=it;i++){
				k=x%v[i];
				if(!k)k+=v[i];
				s[i].erase(s[i].find(f[i][k]));
				f[i][k]-=a[x]*v[i];
				f[i][k]+=1ll*y*v[i];
				s[i].insert(f[i][k]);
			}
			a[x]=y;
			get();
		}
		
		for(i=1;i<=it;i++){
			f[i]=vector<ll>(0,0);
			multiset<ll> clr;
			s[i]=clr;
		}
	}
}