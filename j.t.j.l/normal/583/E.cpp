#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int gcd(int p, int q){
	return q ? gcd(q, p % q) : p;
}

int a[MAXN];
int vis[MAXN];
int fac[MAXN];
ll ans[200010];
int f[MAXN];
vector<int> E[2000];
/*
long long P[MAXN], Q[MAXN];
int g[MAXN];
*/
int main(){
	int n; cin>>n; int mx = 0; int cnt = 0;
	for(int i = 0; i <  n; i++)
		scanf("%d", &a[i]) ,mx = max(mx, a[i]);
	for(int i = 0; i < n; i++)
		cnt += (a[i] == a[mx]);
	for(int i = 1; i < n; i++)
		fac[i] = gcd(n, i);
	sort(fac + 1, fac + n);
	int m = unique(fac + 1, fac + n) - fac - 1;
	map<int, int> mp;
	for(int k = 1; k <= m; k++)
		mp[fac[k]] = k;
	for(int i = 1; i < n; i++){
		int tmp = gcd(n, i);
		int k = mp[tmp];
		E[k].push_back(i);
	}
	long long Umi = 0;
	for(int k = 1; k <= m; k++){
		int p = fac[k];
//		cout<<"^^^^^^^^^^^^^"<<p<<endl;
		for(int i = 0; i < n; i++){
			vis[i] = 0;
		}
		for(int i = 0; i < p; i++){
			int tt = 0;
			for(int j = i; j < n; j += p)
				tt = max(tt, a[j]);
			for(int j = i; j < n; j += p)
				if (tt == a[j])
					vis[j] = 1;
		}
/*
		for(int i = 0; i < n; i++)
			cout<<vis[i]<<' ';cout<<endl;
*/
		int tot = 0;
		for(int i = 0; i < n; i++)
			tot += vis[i];
		if (tot == n){
			for(int i = 1; i <= n; i++)
				ans[i] = n;
		}
		else{
			for(int i = 1; i <= n; i++)
				f[i] = 0;
			int o = 0;
			for(; vis[o]; o++);
			int now = 0;
			for(int i = 0; i <= n; i++){
				if (!vis[(i + o) % n]){
					if (now != 0)
						f[now]++;
					now = 0;
				}
				else
					now++;
			}
			int P = 0, Q = 0;
			for(int i = n; i >= 1; i--){
				P += (long long)i * f[i];
				Q += f[i];
				ans[i] = P - (i - 1) * Q;
			}
		}
		for(int i = 0; i < E[k].size(); i++)
			Umi += ans[E[k][i]];
/*
		for(int i = 1; i <= n; i++)
			cout<<f[i]<<' '; cout<<endl;
		for(int i = 1; i <= n; i++)
			cout<<ans[k][i]<<' '; cout<<endl;
*/
	}
//	cout<<endl;
	/*
	map<int, int> mp;
	for(int k = 1; k <= m; k++)
		mp[fac[k]] = k;
	long long Umi = 0;
	for(int i = 1; i < n; i++){
		int Nico = gcd(n, i), Maki = mp[Nico];
		Umi += ans[Maki][i];
		//cout<<i<<' '<<Nico<<' '<<Maki<<' '<<Umi<<endl;
	}
	*/
	cout<<Umi<<endl;
	return 0;
}