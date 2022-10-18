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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, ans=0;
	cin>>n>>m;
	while(m>n){
		if(m%2) m++;
		else m/=2;
		ans++;
	}
	if(m<n){
		ans+=n-m;
		m+=n-m;
	}
	cout<<ans<<ent;
	return 0;
}