// Krzysztof Boryczka
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

const int N=1010;

int t[N], n;

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	int l=0, r=n+1, rund=0, suma=0, sumb=0, prevsum=0;
	while(l+1<r){
		rund++;
		if(rund % 2 == 1){
			int akt=0;
			while(akt <= prevsum && l+1<r) akt+=t[++l];
			suma+=akt;
			prevsum=akt;
		}
		else{
			int akt=0;
			while(akt <= prevsum && l+1<r) akt+=t[--r];
			sumb+=akt;
			prevsum=akt;
		}
	}
	cout<<rund<<sp<<suma<<sp<<sumb<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt){
		// cout<<"Case #"<<te<<": ";
		solve();
	}
	// solve();
	return 0;
}