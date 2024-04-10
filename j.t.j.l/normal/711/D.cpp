#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

int n, m;
char s[MAXM];
int a[MAXM];
int vis[MAXM];
int f[MAXN][MAXN];
vector<int> E[MAXM];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

ll pw(ll p){
	ll ret = 1;
	ll q = 2;
	for(; p; p>>=1){
		if (p & 1)
			ret = (ret * q) % MM;
		q = q * q % MM;
	}
	return ret;
}

ll work(int u){
	int p = E[u].size(), q;
	for(int i = E[u][0], cnt = 1; cnt <= p + 1; ){
		if (vis[i] != 0){
			q = cnt - vis[i];
			break;
		}
		vis[i] = cnt;
		cnt++;
		i = a[i];
	}
//	cout<<p<<' '<<q<<endl;
	return ( (pw(p) - pw(p-q+1)) % MM + MM ) % MM;
}

int fa[MAXM];

int getfather(int x){
	if (fa[x] == x)
		return x;
	else	
		return fa[x] = getfather(fa[x]);
}

void solve(){
	for(int i = 1; i <= n; i++)
		vis[i] = 0, fa[i] = i;
	ll ans = 1;
	for(int i = 1; i <= n; i++){
		int p = getfather(i), q = getfather(a[i]);
		fa[p] = q;
	}
	for(int i = 1; i <= n; i++)
		getfather(i);
	for(int i = 1; i <= n; i++)
		E[i].clear();
	for(int i = 1; i <=n; i++)
		E[fa[i]].push_back(i);
	for(int i = 1; i <= n; i++)
		if (!E[i].empty()){
			ans = (ans * work(i)) % MM;
		}
	cout<<ans<<endl;
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}