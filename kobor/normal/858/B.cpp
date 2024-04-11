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

const int N=105;

int ans=-1;
int mink[N], maxk[N];
int n, m;

bool check(int il){
	FOR(i, 1, 103){
		if((mink[i]==mink[0] || il*(i-1)<=mink[i]) && (maxk[i] == maxk[0] || maxk[i]<=il*i-1)) continue;
		return 0;
	}
	return 1;
}

void solve(){
	memset(mink, inf, sizeof(mink));
	memset(maxk, -inf, sizeof(maxk));
	cin>>m>>n;
	m--;
	FOR(i, 1, n){
		int a, b;
		cin>>a>>b;
		a--;
		mink[b]=min(mink[b], a);
		maxk[b]=max(maxk[b], a);
	}
	FOR(i, 1, 102){
		if(check(i)){
			if(ans!=-1 && m/i+1!=ans){
				cout<<-1<<ent;
				return;
			}
			ans=m/i+1;
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}