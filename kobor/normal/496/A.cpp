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

int t[110];
int n;

int usu(int a){
	int ret=0, pom=t[a];
	t[a]=t[a-1];
	FOR(i, 1, n-1) ret=max(ret, t[i+1]-t[i]);
	t[a]=pom;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ans=inf;
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 2, n-1) ans=min(ans, usu(i));
	cout<<ans<<ent;
	return 0;
}