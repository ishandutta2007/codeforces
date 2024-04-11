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

bool vis[250];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	for(auto x: s){
		if(x<='Z') x+=32;
		vis[x]=1;
	}
	FOR(i, 'a', 'z') if(!vis[i]){
		cout<<"NO"<<ent;
		return 0;
	}
	cout<<"YES"<<ent;
	return 0;
}