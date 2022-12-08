#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define mp make_pair

//0 conectado a nada
//1 conectado a todos os anteriores
vector<bool> solve(vector<int> v){
	vector<bool> par;
	if(v.size()==0){
		par.pb(0);
		return par;
	}
	if(v.size()==1){
		for(int i=0;i<v[0]+1;i++){
			par.pb(1);
		}
		return par;
	}
	vector<int> vv;
	for(int i=1;i<v.size()-1;i++)vv.pb(v[i]-v[0]);
	par=solve(vv);
	for(int i=0;i<v[v.size()-1]-v[v.size()-2];i++){
		par.pb(0);
	}
	for(int i=0;i<v[0];i++){
		par.pb(1);
	}
	return par;
}


int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb(x);
	}
	vector<bool> sla=solve(v);
	vector<pii> ans;
	for(int i=0;i<sla.size();i++){
		if(sla[i]==0)continue;
		for(int j=0;j<i;j++)ans.pb(mp(j+1,i+1));
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x.f<<" "<<x.s<<endl;
	

    return 0;
}