//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

int n, m;
queue<ii> q;
ii v1, v2;
char t[2010][2010];

bool gut(int a, int b){
	return a>0 && a<n && b>0 && b<m;
}

ii repair(ii v){
	ii ret;
	int cnt=0;
	FOR(i, 0, 1) FOR(j, 0, 1) if(t[v.st+i][v.nd+j]=='*'){
		cnt++;
		ret={v.st+i, v.nd+j};
	}
	if(cnt==1) return ret;
	return {0, 0};
}

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) FOR(j, 1, m) cin>>t[i][j];
	FOR(i, 1, n-1) FOR(j, 1, m-1) q.push({i, j});
	while(!q.empty()){
		v1=q.front();
		q.pop();
		v2=repair(v1);
		if(v2.st){
			t[v2.st][v2.nd]='.';
			FOR(i, 0, 1) FOR(j, 0, 1) if(gut(v2.st-i, v2.nd-j)) q.push({v2.st-i, v2.nd-j});
		}
	}
	FOR(i, 1, n){
		FOR(j, 1, m) cout<<t[i][j];
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}