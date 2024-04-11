#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 11234
#define INF LLONG_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int> 
#define int long long

//onde comeca e tamanho
//0 colunas 1 linhas
set<pii> s[2];
vector<int> cortes[2];

int32_t main(){

	int col,lin,q;
	cin>>lin>>col>>q;

	cortes[0].pb(0);
	cortes[1].pb(0);
	cortes[0].pb(col);
	cortes[1].pb(lin);

	vector<pair<char,int>> queries;

	for(int i=0;i<q;i++){
		char c;int x;
		cin>>c>>x;
		queries.pb(mp(c,x));
		if(c=='H'){
			cortes[0].pb(x);
		}
		else cortes[1].pb(x);
	}

	for(int i=0;i<2;i++)
		sort(cortes[i].begin(),cortes[i].end());

	int maxi[2]={0,0};

	for(int d=0;d<2;d++){
		for(int i=0;i<(int)cortes[d].size()-1;i++){
			s[d].insert(mp(cortes[d][i],cortes[d][i+1]-cortes[d][i]));
			maxi[d]=max(maxi[d],cortes[d][i+1]-cortes[d][i]);
		}
	}

	reverse(queries.begin(),queries.end());

	vector<int> resp;
	for(int i=0;i<q;i++){

		resp.pb(maxi[0]*maxi[1]);
		int d=1;
		if(queries[i].f=='H')d=0;
		auto inter=*s[d].lower_bound(mp(queries[i].s,0));
		auto it=s[d].lower_bound(mp(queries[i].s,0));
		it--;
		auto inter2=*it;
		s[d].erase(inter);
		s[d].erase(inter2);
		s[d].insert(mp(inter2.f,inter.s+inter2.s));
		maxi[d]=max(maxi[d],inter.s+inter2.s);
	}

	reverse(resp.begin(),resp.end());
	for(auto x:resp)cout<<x<<endl;



	return 0;
}