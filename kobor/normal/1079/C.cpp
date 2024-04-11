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

const int N=1e5+10;
bool jakie[N][6];
int odp[N], t[N];

void wgore(int v){
	FOR(k, 1, 5){
		if(jakie[v-1][k]){
			FOR(j, k+1, 5){
				jakie[v][j]=true;
			}
			break;
		}
	}
}

void wdol(int v){
	FORD(k, 5, 1){
		if(jakie[v-1][k]){
			FORD(j, k-1, 1){
				jakie[v][j]=true;
			}
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	bool ahoj=true;
	cin>>n;
	FOR(i, 1, n){
		cin>>t[i];
	}
	FOR(j, 1, 5){
		jakie[1][j]=true;
	}
	FOR(i, 2, n){
		if(t[i-1]<=t[i]){
			wgore(i);
		}
		if(t[i-1]>=t[i]){
			wdol(i);
		}
	}
	FOR(k, 1, 5){
		if(jakie[n][k]){
			ahoj=false;
			odp[n]=k;
			break;
		}
	}
	if(ahoj){
		cout<<-1<<ent;
		return 0;
	}
	FORD(i, n-1, 1){
		if(t[i]<=t[i+1]){
			FORD(k, odp[i+1]-1, 1){
				if(jakie[i][k]){
					odp[i]=k;
					break;
				}
			}
		}
		if(t[i]>=t[i+1]){
			FOR(k, odp[i+1]+1, 5){
				if(jakie[i][k]){
					odp[i]=k;
					break;
				}
			}
		}
	}
	FOR(i, 1, n){
		cout<<odp[i]<<sp;
	}
	cout<<ent;
	return 0;
}