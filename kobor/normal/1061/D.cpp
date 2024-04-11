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

const int N=1e5+9;
const ll MOD=1e9+7;

vector<pair<ii, int> > eve;
stack<int> tv;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a1, b1;
	ll a, b, odp=0;
	cin>>n>>a>>b;
	FOR(i, 1, n){
		cin>>a1>>b1;
		eve.pb({{a1, 0}, b1});
		eve.pb({{b1, 1}, a1});
	}
	sort(eve.begin(), eve.end());
	for(auto x: eve){
		if(x.st.nd==1){	//koniec
			tv.push(x.st.st);
		}
		else{
			if(tv.empty()){
				odp+=a+b*(x.nd-x.st.st);
			}
			else if(a+b*(x.nd-x.st.st) <= b*(x.nd-tv.top())){
				odp+=a+b*(x.nd-x.st.st);
			}
			else{
				odp+=b*(x.nd-tv.top());
				tv.pop();
			}
			odp%=MOD;
		}
	}
	cout<<odp<<ent;
	return 0;
}