#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define pb push_back
double its(pll a, pll b){
	return ((double)a.se-b.se)/((double)b.fi-a.fi);
}

void solve(){
	int N; cin >> N;
	vector<array<ll,3>> v(N);
	for(auto &i: v)cin >>i[0] >> i[1] >> i[2];
	sort(v.begin(),v.end());
	vector<ll> ans(N);
	ans[0] = v[0][0]*v[0][1]-v[0][2];
	vector<pll> ch;
	vector<double> p;
	ch.pb({-v[0][0],ans[0]});

	int ind = 0;
	pll cur;
	for(int i = 1; i < N; i++){
		while(ind < p.size() && (double)v[i][1]<=p[ind])ind++;
		ind = min(ind,(int)ch.size()-1);
		ans[i] = max(v[i][0] * v[i][1], ch[ind].se + (v[i][0]+ch[ind].fi)*v[i][1]) - v[i][2];
		cur = {-v[i][0],ans[i]};
		while(p.size() > 0){
			if(its(cur,ch.back()) <= p.back())break;
			ch.pop_back(); p.pop_back();
		}
		p.pb(its(cur,ch.back()));
		ch.pb(cur);
	}
	ll res = 0;
	for(ll x: ans)res = max(x,res);
	//for(auto x: ans)cout << x << " ";
	cout << res << endl;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(NULL);
	solve();
	return 0;
}