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

#define LSB(x) ((x)&(-x))

vi oper;
int a, ans;

bool gut(){
	int pom=a+1;
	return pom==LSB(pom);
}

void perform(){
	int pom;
	for(int i=0; (1<<i)<=a; i++){
		if((a&(1<<i))==0) pom=i;
	}
	a^=(1<<(pom+1))-1;
	oper.pb(pom+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>a;
	while(!gut()){
		perform();
		ans++;
		if(gut()) break;
		a++;
		ans++;
	}
	cout<<ans<<ent;
	for(auto x: oper) cout<<x<<sp;
	cout<<ent;
	return 0;
}