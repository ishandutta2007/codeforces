//Krzysztof Boryczka
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

int n, m, ans=inf;
int t[1010][1010];
int najkr[4][1010][1010];
int xx[4]={0, 1, 0, -1}, yy[4]={1, 0, -1, 0};

void bfs(int g){
	deque<ii> q;
	ii v;
	int kara;
	FOR(i, 1, n) FOR(j, 1, m) if(t[i][j]==g){
		q.pb({i, j});
		najkr[g][i][j]=0;
		break;
	}
	while(!q.empty()){
		v=q.front();
		q.pop_front();
		FOR(k, 0, 3){
			if(t[v.st+xx[k]][v.nd+yy[k]]==0) kara=inf;
			else if(t[v.st+xx[k]][v.nd+yy[k]]==4) kara=1;
			// else if(t[v.st][v.nd]<4) kara=0;
			else kara=0;
			if(najkr[g][v.st][v.nd]+kara<najkr[g][v.st+xx[k]][v.nd+yy[k]]){
				najkr[g][v.st+xx[k]][v.nd+yy[k]]=najkr[g][v.st][v.nd]+kara;
				if(kara==1) q.pb({v.st+xx[k], v.nd+yy[k]});
				else q.push_front({v.st+xx[k], v.nd+yy[k]});
			}
		}
	}
}

void solve(){
	string s;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>s;
		FOR(j, 1, m){
			if(s[j-1]=='.') t[i][j]=4;
			else if(s[j-1]!='#') t[i][j]=s[j-1]-'0';
		}
	}
	memset(najkr, inf, sizeof(najkr));
	FOR(k, 1, 3) bfs(k);

	FOR(i, 1, n) FOR(j, 1, m) ans=min(ans, min(inf, najkr[1][i][j]+najkr[2][i][j])+najkr[3][i][j]);
	if(ans==0){
		cout<<ans<<ent;
		return;
	}

	ans=inf;
	FOR(i, 1, n) FOR(j, 1, m) if(t[i][j]==4) ans=min(ans, min(inf, najkr[1][i][j]+najkr[2][i][j])+najkr[3][i][j]);
	// FOR(i, 1, n) FOR(j, 1, m) if(ans==min(inf, najkr[1][i][j]+najkr[2][i][j])+najkr[3][i][j]) cout<<i<<sp<<j<<ent;
	if(ans==inf) ans=1;
	cout<<ans-2<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}