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

string s;
int inv[10];
int para[10][10];

void licz(int a, int b, int x, int y){
	para[a][b]=inf;
	FOR(i, 0, 9) FOR(j, 0, 9){
		if(i==0 && j==0) continue;
		if((a+x*i+y*j)%10==b) para[a][b]=min(para[a][b], i+j);
	}
}

int rozw(int a, int b){
	int ret=0;
	FOR(i, 0, 9) FOR(j, 0, 9) licz(i, j, a, b);
	FOR(i, 0, SIZE(s)-2){
		ret+=para[s[i]-'0'][s[i+1]-'0'];
		ret=min(ret, inf);
	}
	return (ret==inf?-1:ret-SIZE(s)+1);
}

void solve(){
	cin>>s;
	FOR(i, 0, 9){
		FOR(j, 0, 9) cout<<rozw(i, j)<<sp;
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}