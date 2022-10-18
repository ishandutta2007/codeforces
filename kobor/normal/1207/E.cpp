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

void solve(){
	int ans1, ans2;

	cout<<"? ";
	FOR(i, 1, 100) cout<<i<<sp;
	cout<<endl;
	cin>>ans1;

	cout<<"? ";
	FOR(i, 1, 100) cout<<i*128<<sp;
	cout<<endl;
	cin>>ans2;

	cout<<"! ";
	cout<<ans1/128*128+ans2%128<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}