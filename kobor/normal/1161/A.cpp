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

const int N=1e5+5;

int cnt[N];
set<ii> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k, a, ans;
	cin>>n>>k;
	if(n==1){
		cout<<0<<ent;
		return 0;
	}
	ans=(n-2)*3+4;
	FOR(i, 1, k){
		cin>>a;
		cnt[a]++;
		if(cnt[a-1]) s.insert({a, a-1});
		if(cnt[a+1]) s.insert({a, a+1});
		s.insert({a, a});
	}
	cout<<ans-SIZE(s)<<ent;
	return 0;
}