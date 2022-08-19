#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 300005;
const int mod = 1e9 + 7;

int n, m, a[MAXN][10];
int has[256], whohas[256];
int ansi, ansj;

bool trial(int x){
	memset(has, 0, sizeof(has));
	memset(whohas, -1, sizeof(whohas));
	for(int i=1; i<=n; i++){
		int msk = 0;
		for(int j=0; j<m; j++){
			if(a[i][j] >= x) msk |= (1<<j);
		}
		if(!has[msk]){
			has[msk] = 1;
			whohas[msk] = i;
		}
	}
	for(int i=0; i<(1<<m); i++){
		for(int j=0; j<(1<<m); j++){
			if((i | j) == (1<<m) - 1 && has[i] && has[j]){
				ansi = whohas[i];
				ansj = whohas[j];
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++) scanf("%d",&a[i][j]);
	}
	int s = 0, e = 1e9;
	while(s != e){
		int m = (s+e+1)/2;
		if(trial(m)) s = m;
		else e = m - 1;
	}
	trial(s);
	printf("%d %d\n", ansi, ansj);
}