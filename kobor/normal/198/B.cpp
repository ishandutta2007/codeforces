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

const int N=1e5+5;

int dp[N][2];
int n, k;
string s[2];
queue<ii> stany;

void solve(){
    memset(dp, inf, sizeof(dp));
    cin>>n>>k>>s[0]>>s[1];
    dp[1][0]=0;
    stany.push({1, 0});
    while(!stany.empty()){
        auto v=stany.front();
        stany.pop();
        for(auto x: {make_pair(v.st+1, v.nd), make_pair(v.st-1, v.nd), make_pair(v.st+k, v.nd^1)}){
            x.st=max(1, min(n+1, x.st));
            if(s[x.nd][x.st-1]=='X') continue;
            if(dp[x.st][x.nd]==inf && dp[v.st][v.nd]+1<x.st){
                dp[x.st][x.nd]=dp[v.st][v.nd]+1;
                stany.push({x.st, x.nd});
            }
        }
    }
    cout<<(dp[n+1][0]!=inf || dp[n+1][1]!=inf ? "YES" : "NO")<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}