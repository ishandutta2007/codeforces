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

const int N=5e5+5;

bool sito[N];
int zlicz[4];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, pt, a;
	cin>>n;
	sito[0]=sito[1]=1;
	for(int i=2; i*i<=n*2; i++){
		if(sito[i]) continue;
		for(int j=i*i; j<=n*2; j+=i) sito[j]=1;
	}
	FOR(i, 1, n){
		cin>>a;
		zlicz[a]++;
	}
	pt=0;
	while(zlicz[1] && zlicz[2]){
		if(!sito[pt+1]){
			cout<<1<<sp;
			zlicz[1]--;
			pt++;
		}
		else{
			cout<<2<<sp;
			zlicz[2]--;
			pt+=2;
		}
	}
	FOR(i, 1, zlicz[1]) cout<<1<<sp;
	FOR(i, 1, zlicz[2]) cout<<2<<sp;
	cout<<ent;
	return 0;
}