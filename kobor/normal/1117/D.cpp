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

const ll mod=1e9+7;

ll n, m;
ll mat[110][110], bmat[110][110], pmat[110][110];

void mnoz(){
	FOR(i, 1, m){
		FOR(j, 1, m){
			pmat[i][j]=mat[i][j];
			mat[i][j]=0;
		}
	}
	FOR(i, 1, m){
		FOR(j, 1, m){
			FOR(k, 1, m){
				mat[i][j]+=pmat[i][k]*bmat[k][j];
				mat[i][j]%=mod;
			}
		}
	}
}

void kwadrac(){
	FOR(i, 1, m){
		FOR(j, 1, m){
			pmat[i][j]=mat[i][j];
			mat[i][j]=0;
		}
	}
	FOR(i, 1, m){
		FOR(j, 1, m){
			FOR(k, 1, m){
				mat[i][j]+=pmat[i][k]*pmat[k][j];
				mat[i][j]%=mod;
			}
		}
	}
}

void pow(ll a){
	if(a==1){
		return;
	}
	if(a%2==1){
		pow(a-1);
		mnoz();
	}
	else{
		pow(a/2);
		kwadrac();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	bmat[m][1]=bmat[1][1]=1;
	mat[m][1]=mat[1][1]=1;
	FOR(i, 2, m){
		bmat[i-1][i]=mat[i-1][i]=1;
	}
	pow(n);
	cout<<(mat[1][1])%mod<<ent;
	return 0;
}