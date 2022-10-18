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

vi perm[24]={{0, 1, 2, 3, 4, 5}, {0, 2, 3, 4, 1, 5}, {0, 3, 4, 1, 2, 5}, {0, 4, 1, 2, 3, 5},
			 {5, 4, 3, 2, 1, 0}, {5, 1, 4, 3, 2, 0}, {5, 2, 1, 4, 3, 0}, {5, 3, 2, 1, 4, 0},
			 {1, 5, 2, 0, 4, 3}, {1, 2, 0, 4, 5, 3}, {1, 0, 4, 5, 2, 3}, {1, 4, 5, 2, 0, 3},
			 {3, 4, 0, 2, 5, 1}, {3, 5, 4, 0, 2, 1}, {3, 2, 5, 4, 0, 1}, {3, 0, 2, 5, 4, 1},
			 {2, 1, 5, 3, 0, 4}, {2, 5, 3, 0, 1, 4}, {2, 3, 0, 1, 5, 4}, {2, 0, 1, 5, 3, 4},
			 {4, 0, 3, 5, 1, 2}, {4, 1, 0, 3, 5, 2}, {4, 5, 1, 0, 3, 2}, {4, 3, 5, 1, 0, 2}};

string s;
set<string> ans;

void solve(){
	cin>>s;
	sort(s.begin(), s.end());
	do{
		string mil="ZZZZZZ";
		FOR(k, 0, 23){
			string dod="ZZZZZZ";
			FOR(i, 0, SIZE(s)-1) dod[i]=s[perm[k][i]];
			mil=min(mil, dod);
		}
		ans.insert(mil);
	}while(next_permutation(s.begin(), s.end()));
	cout<<SIZE(ans)<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}