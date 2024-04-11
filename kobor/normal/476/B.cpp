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

ll fac(int a){
	ll ret=1;
	FOR(i, 1, a) ret*=i;
	return ret;
}

ll bin(int n, int k){
	if(k>n || k<0) return 0;
	return fac(n)/fac(k)/fac(n-k);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a, b;
	int pos, pyts;
	ld ans;
	cin>>a>>b;
	pos=pyts=0;
	for(auto x: a){
		if(x=='+') pos++;
		else if(x=='-') pos--;
	}
	for(auto x: b){
		if(x=='+') pos--;
		else if(x=='-') pos++;
		else pyts++;
	}
	pos=abs(pos);
	if((pyts-pos)%2) ans=0;
	else ans=(ld)bin(pyts, (pyts-pos)/2);
	FOR(i, 1, pyts) ans/=2;
	cout<<fixed<<setprecision(10);
	cout<<ans<<ent;
	return 0;
}