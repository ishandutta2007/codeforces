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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

#define x first
#define y second

vector<pair<ld, ld> > pt;
vii ptodp;
ld odp;
map<ii, bool> M;

ld dist(int a, int b){
	return hypot(pt[a].x-pt[b].x, pt[a].y-pt[b].y);
}

ld dl(int a, int b, int c, int d){
	return dist(a, b)+dist(b, c)+dist(c, d);
}

bool git(int a, int b, int c, int d){
	set<int> g;
	g.clear();
	g.insert(a);
	g.insert(b);
	g.insert(c);
	g.insert(d);
	return SIZE(g)==4;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	bool tr=false;
	cin>>n>>m;
	if(n<m){
		swap(n, m);
		tr=true;
	}
	FOR(i, 0, min(n, 3)){
		FOR(j, 0, min(m, 3)){
			if(!M[{i,j}]){
				pt.pb({i, j});
				M[{i, j}]=true;
			}
			if(!M[{n-i, m-j}]){
				pt.pb({n-i, m-j});
				M[{n-i, m-j}]=true;
			}
		}
	}
	FOR(i, 0, SIZE(pt)-1){
		FOR(j, 0, SIZE(pt)-1){
			FOR(k, 0, SIZE(pt)-1){
				FOR(l, 0, SIZE(pt)-1){
					if(git(i, j, k, l)){
						if(dl(i, j, k, l)>odp){
							odp=dl(i, j, k, l);
							ptodp.clear();
							ptodp={pt[i], pt[j], pt[k], pt[l]};
						}
					}
				}
			}
		}
	}
	for(auto ok: ptodp){
		if(tr){
			swap(ok.x, ok.y);
		}
		cout<<ok.x<<sp<<ok.y<<ent;
	}
	return 0;
}