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
const int N=200010;

bool who[N];
int pos[N], neks[N], prew[N], odp[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	FOR(i, 1, n+m){
		cin>>pos[i];
	}
	FOR(i, 1, n+m){
		cin>>who[i];
	}
	pos[0]=-inf;
	pos[n+m+1]=2*inf;
	who[0]=who[n+m+1]=true;
	prew[0]=0;
	neks[n+m+1]=n+m+1;
	FOR(i, 1, n+m){
		prew[i]=prew[i-1];
		if(who[i]){
			prew[i]=i;
		}
	}
	FORD(i, n+m, 1){
		neks[i]=neks[i+1];
		if(who[i]){
			neks[i]=i;
		}
	}
	FOR(i, 1, n+m){
		if(who[i])
			continue;
		if(pos[i]-pos[prew[i]]<=pos[neks[i]]-pos[i]){
			odp[prew[i]]++;
		}
		else{
			odp[neks[i]]++;
		}
	}
	FOR(i, 1, n+m)
		if(who[i])
			cout<<odp[i]<<sp;
	cout<<ent;
	return 0;
}