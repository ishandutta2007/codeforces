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

const int N=1e6;

bool vis[N+5];
vi G[N+5];
int xx[8]={1, 2, 2, 1, -1, -2, -2, -1}, yy[8]={2, 1, -1, -2, -2, -1, 1, 2};
int kumpel[N+5];
int n, m, mm;

bool gut(int a, int b){
	if(a>-1 && a<n && b>-1 && b<m){
		return true;
	}
	return false;
}

int nr(int a, int b){
	return a+b*n+1;
}

bool match(int v){
	vis[v]=true;
	for(auto x: G[v]){
		if(!vis[x] && (vis[x]=true) && (!kumpel[x] || match(kumpel[x]))){
			kumpel[x]=v;
			kumpel[v]=x;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool flag=true;
	cin>>n>>m;
	FOR(i, 0, n-1){
		FOR(j, 0, m-1){
			FOR(k, 0, 7){
				if(gut(i+xx[k], j+yy[k])){
					G[nr(i, j)].pb(nr(i+xx[k], j+yy[k]));
				}
			}
		}
	}
	while(flag){
		flag=false;
		FOR(i, 1, n*m){
			if(!vis[i] && !kumpel[i] && match(i)){
				flag=true;
				mm++;
			}
		}
		FOR(i, 1, n*m){
			vis[i]=false;
		}
	}
	cout<<n*m-mm<<ent;
	return 0;
}