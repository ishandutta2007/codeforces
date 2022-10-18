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

const int N=1e6+6;

const int mod=1e9+123;
const int pp[2]={29, 31};

int p[N][2]={{1, 1}};
int prefhasz[N][2], sufhasz[N][2];

int wyn(string s){
	s='#'+s;
	for(auto &x: s) x-='a'-1;
	FOR(i, 1, SIZE(s)-1) FOR(j, 0, 1) prefhasz[i][j]=((ll)prefhasz[i-1][j]*pp[j]+s[i])%mod;
	FOR(i, 1, SIZE(s)-1) FOR(j, 0, 1) sufhasz[i][j]=((ll)p[i-1][j]*s[i]+sufhasz[i-1][j])%mod;
	FORD(i, SIZE(s)-1, 2) if(prefhasz[i][0] == sufhasz[i][0] && prefhasz[i][1] == sufhasz[i][1]) return i;
	return 1;
}

void solve(){
	int kd;
	string s, slo, rslo, pom;
	cin>>s;
	if(SIZE(s)==1){
		cout<<s<<ent;
		return;
	}
	FOR(i, 0, SIZE(s)/2-1){
		kd=i;
		if(s[i]==s[SIZE(s)-i-1]) pom+=s[i];
		else break;
		if(i==SIZE(s)/2-1){
			cout<<s<<ent;
			return;
		}
	}
	slo=s.substr(kd, SIZE(s)-kd*2);
	rslo=slo;
	reverse(rslo.begin(), rslo.end());
	int a=wyn(slo), b=wyn(rslo);
	if(SIZE(pom)) cout<<pom;
	if(a>b) cout<<slo.substr(0, a);
	else{
		rslo=rslo.substr(0, b);
		reverse(rslo.begin(), rslo.end());
		cout<<rslo;
	}
	reverse(pom.begin(), pom.end());
	if(SIZE(pom)) cout<<pom;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FOR(i, 1, N-2) FOR(j, 0, 1) p[i][j]=(ll)p[i-1][j]*pp[j]%mod;
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}