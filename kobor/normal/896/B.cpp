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

const int N=1010;

int n, m, c, l, r, p;
int t[N];

void solve(){
	cin>>n>>m>>c;
	c>>=1;
	l=1; r=n;
	while(l<=r){
		cin>>p;
		if(p<=c){
			m=upper_bound(t+1, t+l, p)-t;
			l+=(m==l);
		}
		else{
			m=lower_bound(t+r+1, t+n+1, p)-t-1;
			r-=(m==r);
		}
		t[m]=p;
		cout<<m<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}