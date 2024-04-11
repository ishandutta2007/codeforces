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

int n, ans;

bool ok(int num){
	int cnt[10]={0};
	int cyk=0;
	while(num){
		cnt[num%10]++;
		num/=10;
	}
	FOR(i, 0, 9) cyk+=cnt[i]>0;
	return cyk<=2;
}

void akt(int xd){
	if(xd>n) return;
	ans++;
	if(xd>=(int)1e8) return;
	FOR(i, 0, 9) if(ok(xd*10+i)) akt(xd*10+i);
}

void solve(){
	cin>>n;
	if(n==(int)1e9) ans++, n--;
	FOR(i, 1, 9) akt(i);
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