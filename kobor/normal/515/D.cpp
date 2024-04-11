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

const int N=2020;

char t[N][N];
int xx[4]={0, 1, 0, -1}, yy[4]={1, 0, -1, 0};
int n, m;
ii v, x;
bool syf;
queue<ii> q;

bool paruj(int xa, int ya, int xb, int yb){
	if(t[xa][ya]!='.' || t[xb][yb]!='.') return 0;
	if(xa>xb) swap(xa, xb);
	if(ya>yb) swap(ya, yb);
	if(xa==xb){
		t[xa][ya]='<'; t[xb][yb]='>';
	}
	else{
		t[xa][ya]='^'; t[xb][yb]='v';
	}
	return 1;
}

int deg(int xa, int ya){
	int ret=0;
	FOR(k, 0, 3) ret+=(t[xa+xx[k]][ya+yy[k]]=='.');
	return ret;
}

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) FOR(j, 1, m) cin>>t[i][j];
	FOR(i, 1, n) FOR(j, 1, m) if(t[i][j]=='.' && deg(i, j)==1) q.push({i, j});
	while(!q.empty() && !syf){
		v=q.front();
		q.pop();
		if(t[v.st][v.nd]!='.') continue;
		x.st=0;
		FOR(k, 0, 3) if(t[v.st+xx[k]][v.nd+yy[k]]=='.') x={v.st+xx[k], v.nd+yy[k]};
		if(!x.st || !paruj(v.st, v.nd, x.st, x.nd)){
			syf=1;
			break;
		}
		FOR(k, 0, 3) if(t[x.st+xx[k]][x.nd+yy[k]]=='.' && deg(x.st+xx[k], x.nd+yy[k])==1) q.push({x.st+xx[k], x.nd+yy[k]});
	}
	FOR(i, 1, n) FOR(j, 1, m) if(syf || t[i][j]=='.'){
		cout<<"Not unique\n";
		return;
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