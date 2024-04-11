//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int INF=1e9+9;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define DEBUG(x) x
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int n;
int t[1010];
bool vis[1010];

int dfs(int v){
	vis[v]=true;
	if(vis[t[v]]){
		return t[v];
	}
	return dfs(t[v]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			vis[j]=false;
		}
		cout<<dfs(i)<<sp;
	}
	cout<<ent;
	return 0;
}