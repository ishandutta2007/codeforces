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

string s1, s2;
int pos, pp;

void solve(){
	cin>>s1>>s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	FOR(i, 0, SIZE(s2)-1){
		if(s2[i]=='1'){
			pos=i;
			break;
		}
	}
	pp=pos;
	while(s1[pos]!='1') pos++;
	cout<<pos-pp<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}