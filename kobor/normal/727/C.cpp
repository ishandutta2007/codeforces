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

const int N=5050;

int a[N];

void solve(){
	int jed, dwa, tri, n, sum;
	cin>>n;
	cout<<"? 1 2\n? 2 3\n ? 3 1"<<endl;
	cin>>jed>>dwa>>tri;
	sum=(jed+dwa+tri)/2;
	a[1]=sum-dwa;
	a[2]=sum-tri;
	a[3]=sum-jed;
	FOR(i, 4, n){
		cout<<"? 1 "<<i<<endl;
		cin>>jed;
		a[i]=jed-a[1];
	}
	cout<<"! ";
	FOR(i, 1, n) cout<<a[i]<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}