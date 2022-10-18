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
	int n, m;
	cin>>n>>m;
	FOR(i, 1, n){
		FOR(j, 1, m){
			if((i%4==2 && j!=m) || (i%4==0 && j!=1)){
				cout<<'.';
			}
			else{
				cout<<'#';
			}
		}
		cout<<ent;
	}
	return 0;
}