#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;

int n, m;
int pmc = 0;

int pvis[MAXN];
int pm[MAXN], mp[MAXN];

int C[1001111][24];

void prework(){
	for (int i = 2; i < MAXN; ){
		pm[++pmc] = i;
		for (int j = i; j < MAXN; j += i){
			if (pvis[j]==0){
				pvis[j]=1;
				mp[j]=i;
			}
		}
		while(i<MAXN && pvis[i])
			i++;
	}
	C[1][0] = C[1][1] = 1;
	for (int i = 2; i < 1001000; i++){
		if (i <= 21){
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++){
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				if (C[i][j] >= MM) C[i][j] -= MM;
			}
		}
		else{
			C[i][0] = 1;
			for (int j = 1; j <= 21; j++){
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				if (C[i][j] >= MM) C[i][j] -= MM;
			}
		}
	}
	//puts("???");
}

ll pw(ll p, ll q){
	ll ret = 1;
	for (; q; q >>= 1){
		if (q & 1) ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

ll gao(ll x, int n){
	// x <= 20, n <= 1e6
	//cout << n << ' ' << x << endl;
	return C[n + x - 1][x];
}

void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	x=ch-'0';
	while(ch=getchar(), ch>='0'&&ch<='9') x=x*10+ch-'0';
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	//scanf("%d%d", &m, &n);
	read(m);
	read(n);
	vector<int> f;
	while(m!=1){
		int x = mp[m], cnt=0;
		while(mp[m]==x){
			m/=x;
			cnt++;
		}
		f.push_back(cnt);
	}
	/*
	for (int i = 1; pm[i] * pm[i] <= m; i++){//heiheihei
		if (m % pm[i] == 0){
			int cnt = 0;
			while(m % pm[i] == 0){
				cnt++;
				m /= pm[i];
			}
			f.push_back(cnt);
		}
	}
	if (m != 1){
		f.push_back(1);
	}
	*/
	//sort(f.begin(), f.end());
	ll ans = 1;
	for (auto &x : f)if(x)
		ans = (ans * gao(x, n)) % MM;
	ans = ans * pw(2, n - 1) % MM;
	printf("%lld\n", ans);
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
	read(T);
	for(int i = 1; i <= T; i++){
		solve(i);
		printans();
	}
	return 0;
}