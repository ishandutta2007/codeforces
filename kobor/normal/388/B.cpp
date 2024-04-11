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

#define LSB(x) ((x)&(-x))

int k, ak;
bool mat[1010][1010];

void add(int a, int b){
	mat[a][b]=mat[b][a]=1;
}

void buildtower(){
	FOR(i, 3, 39) add(i, i+1);
	add(1, 3);
	add(40, 2);
	ak=40;
}

void path(int h){
	if(!h){
		add(1, ++ak);
		add(ak, 4);
		return;
	}
	add(1, ++ak);
	add(1, ++ak);
	FOR(i, 2, h){
		add(ak-1, ak+1);
		add(ak, ak+1);
		add(ak-1, ak+2);
		add(ak, ak+2);
		ak+=2;
	}
	add(ak-1, h+3);
	add(ak, h+3);
}

void solve(){
	cin>>k; k--;
	buildtower();
	while(k){
		path(__builtin_ctz(k));
		k-=LSB(k);
	}
	cout<<ak<<ent;
	FOR(i, 1, ak){
		FOR(j, 1, ak){
			cout<<(mat[i][j]?'Y':'N');
		}
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}