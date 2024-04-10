#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e5 + 10;
const int MAXM = 6e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];
int L[MAXM], R[MAXM], cnt[MAXM];

ll ans = 0;
int sz;
int nico;

void fuck(int dep, int l, int r, int ret){
	// dep == 1, 2**29
	// dep == 30, 2**0
	if (dep == 30){
		nico = min(nico, ret);
		return ;
	}
	if (cnt[L[l]]){
		if (cnt[L[r]])
			fuck(dep + 1, L[l], L[r], ret);
		else
			fuck(dep + 1, L[l], R[r], ret | (1 << (29 - dep)));
	}
	if (cnt[R[l]]){
		if (cnt[R[r]])
			fuck(dep + 1, R[l], R[r], ret);
		else
			fuck(dep + 1, R[l], L[r], ret | (1 << (29 - dep)));
	}
}

void gao(int dep, int u){
	if (cnt[L[u]])
		gao(dep + 1, L[u]);
	if (cnt[R[u]])
		gao(dep + 1, R[u]);
	if (cnt[L[u]] && cnt[R[u]]){
		nico = 1ll << 30;
		fuck(dep + 1, L[u], R[u], 1 << (29 - dep));
		ans += nico;
	}
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	sz = 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int now = 1;
		cnt[now]++;
		for (int j = 29; j >= 0; j--){
			if ((a[i] >> j) & 1){
				if (R[now] == 0){
					sz++;
					R[now] = sz;
					now = sz;
				}
				else
					now = R[now];
			}
			else{
				if (L[now] == 0){
					sz++;
					L[now] = sz;
					now = sz;
				}
				else
					now = L[now];
			}
			cnt[now]++;
		}
	}
	gao(0, 1);
	printf("%lld\n", ans);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}