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

const int N=5050;

int n, m;
int t[N][N];
int len[N][N];
int pref[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	int ans=0;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>s;
		FOR(j, 1, m){
			t[i][j]=s[j-1]-'0';
		}
	}
	FOR(i, 1, n){
		FORD(j, m, 1){
			len[i][j]=len[i][j+1]+1;
			if(!t[i][j]) len[i][j]=0;
		}
	}
	FOR(j, 1, m){
		FOR(i, 1, n) pref[len[i][j]]++;
		FORD(i, m, 1) pref[i]+=pref[i+1];
		FOR(i, 1, m) ans=max(ans, i*pref[i]);
		memset(pref, 0, sizeof(pref));
	}
	cout<<ans<<ent;
	return 0;
}