#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define FORD(i,b,e) for(int i=b; i>=e; i--)
#define SIZE(x) (int)x.size()
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int SQ=700;
const int N=5e5+5;

int sum[SQ+5][SQ+5];
int t[N];

void solve(){
	int qq, a, b, c; cin>>qq;
	FOR(q, 1, qq){
		cin>>c>>a>>b;
		if(c==1){
			t[a]+=b;
			FOR(i, 1, SQ) sum[i][a%i]+=b;
		}
		else{
			if(a>SQ){
				int ans=0;
				for(int i=b; i<=500000; i+=a) ans+=t[i];
				cout<<ans<<ent;
			}
			else cout<<sum[a][b]<<ent;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}