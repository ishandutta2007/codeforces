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

int a, b;
int x2, y3, y2;

bool isSquare(int v){
	return (int)sqrt(v)*sqrt(v)==v;
}

void solve(){
	cin>>a>>b;
	FOR(x1, 1, a-1){
		if(isSquare(a*a-x1*x1)){
			y3=sqrt(a*a-x1*x1);
			if(b*y3%a==0){
				x2=b*y3/a;
				if(isSquare(b*b-x2*x2)){
					y2=sqrt(b*b-x2*x2);
					if(y3!=y2){
						cout<<"YES"<<ent;
						cout<<"0 0"<<ent;
						cout<<x1<<sp<<y3<<ent;
						cout<<-x2<<sp<<y2<<ent;
						return;
					}
				}
			}
		}
	}
	cout<<"NO"<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}