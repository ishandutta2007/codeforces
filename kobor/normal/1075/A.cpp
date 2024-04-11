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
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, x, y, dist1, dist2;
	cin>>n>>x>>y;
	dist1=x-1+y-1;
	dist2=n-x+n-y;
	if(dist1<=dist2){
		cout<<"White"<<ent;
	}
	else{
		cout<<"Black"<<ent;
	}
	return 0;
}