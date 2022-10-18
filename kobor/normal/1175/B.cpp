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

vi stos;
int pomin;
ll val, mnoz=1;

const ll MX=(1ll<<32)-1;

void solve(){
	string s;
	int n, p; cin>>n;
	FOR(i, 1, n){
		cin>>s;
		if(s=="add"){
			val+=mnoz;
			if(val>MX || pomin){
				cout<<"OVERFLOW!!!"<<ent;
				return;
			}
		}
		else if(s=="end"){
			if(pomin) pomin--;
			else mnoz/=stos.back();
			stos.pop_back();
		}
		else{
			cin>>p;
			if(mnoz*p>MX || pomin) pomin++;
			else mnoz*=p;
			stos.pb(p);
		}
	}
	cout<<val<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}