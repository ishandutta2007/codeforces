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

const int N=2e5+5;

int w, h, n;
multiset<int> s[2];
int t[2][N];
set<int> akt[2]={{0}, {0}};

void tnij(int gdzie, int kt){
	auto pos=prev(akt[kt].lower_bound(gdzie));
	s[kt].erase(s[kt].find(t[kt][*pos]-*pos));
	t[kt][gdzie]=t[kt][*pos];
	t[kt][*pos]=gdzie;
	s[kt].insert(t[kt][gdzie]-gdzie);
	s[kt].insert(t[kt][*pos]-*pos);
	akt[kt].insert(gdzie);
}

void solve(){
	int a;
	char c;
	cin>>w>>h>>n;
	t[0][0]=w;
	t[1][0]=h;
	s[0]={w};
	s[1]={h};
	FOR(i, 1, n){
		cin>>c>>a;
		tnij(a, (c=='H'));
		cout<<(ll)(*prev(s[0].end()))*(*prev(s[1].end()))<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}