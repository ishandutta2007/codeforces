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

bool vis[100010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, m;
	cin>>a>>m;
	while(a){
		a=(a+a%m)%m;
		if(vis[a]){
			cout<<"No\n";
			return 0;
		}
		vis[a]=1;
	}
	cout<<"Yes\n";
	return 0;
}