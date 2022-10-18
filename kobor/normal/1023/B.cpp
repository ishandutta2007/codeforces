//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int INF=1e9+9;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define DEBUG(x) x
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LL a, b, dr, ta;
	cin>>a>>b;
	dr=min(a, b-1);
	ta=b-dr;
	if(ta>0&&ta<=a&&dr>0&&dr<=a&&ta!=dr){
		cout<<abs(dr-ta-1)/2+1<<ent;
		return 0;
	}
	cout<<0<<ent;
	return 0;
}