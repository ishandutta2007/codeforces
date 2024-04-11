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

const int N=1e5+5;

int n;
int t[N];
bool ger[N];
ll sum;
double aa;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	FOR(i, 1, n){
		cin>>aa;
		ger[i]=(aa==floor(aa));
		t[i]=floor(aa);
		sum+=t[i];
	}
	FOR(i, 1, n){
		if(sum!=0 && !ger[i]){
			t[i]++;
			sum++;
		}
		cout<<t[i]<<ent;
	}
	return 0;
}