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

unordered_map<int, int> M;	//0-nie ma, 1-jest, 2-grp 0, 3-grp 1
int n, a, b, dx;
int t[N], ans[N];
ii t2[N];

void solve(){
	cin>>n>>a>>b;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) t2[i]={t[i], i};
	sort(t+1, t+n+1);
	sort(t2+1, t2+n+1);
	if(a<b){
		swap(a, b);
		dx++;
	}
	FOR(i, 1, n) M[t[i]]=1;
	FOR(i, 1, n){
		if(M[t[i]]!=1) continue;
		if(M[a-t[i]]==1 || M[a-t[i]]==2) M[a-t[i]]=M[t[i]]=2;
		else if(M[b-t[i]]==1 || M[b-t[i]]==3) M[b-t[i]]=M[t[i]]=3;
		else{
			cout<<"NO\n";
			return;
		}
	}
	FOR(i, 1, n) ans[t2[i].nd]=(M[t2[i].st]&1)^dx;
	cout<<"YES\n";
	FOR(i, 1, n) cout<<ans[i]<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}