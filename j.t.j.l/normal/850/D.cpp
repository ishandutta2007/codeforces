#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[1000];
int f[80][5000][40];

int deg[MAXN];
int rm[MAXN];
int g[1000][1000];

set<int> st;

int gao(int m){
	// f[m][S][n]
	f[1][a[0]][0] = 1;
	int MS = m * (m - 1) / 2;
	for (int i = 1; i < m; i++){
		for (int j = (i - 1) * i / 2; j <= MS; j++){
			for (int k = 0; k < n; k++){
				if (f[i][j][k]){
					if (j + a[k] <= MS)
						f[i + 1][j + a[k]][k] = 1;
					if (k != n - 1 && j + a[k + 1] <= MS)
						f[i + 1][j + a[k + 1]][k + 1] = 2;
				}
			}
		}
	}
	if (f[m][MS][n - 1] == 0)
		return 0;
	printf("%d\n", m);
	for (int i = 1, p = m, q = MS, r = n - 1; i <= m; i++){
		deg[i] = a[r];
		int pp = p - 1, qq = q - deg[i], rr = r - f[p][q][r] + 1;
		p = pp, q = qq, r = rr;
	}
	//sort(deg + 1, deg + m + 1);
	reverse(deg + 1, deg + m + 1);
	for (int i = 1; i <= m; i++)
		rm[i] = m - 1 - deg[i];
	for (int i = 2; i <= m; i++){
		vector<PII> b;
		for (int j = 1; j < i; j++){
			if (rm[j])
				b.push_back(PII(rm[j], j));
		}
		sort(b.begin(), b.end());
		for (int j = (int)b.size() - 1; j >= 0 && deg[i]; j--){
			rm[b[j].second]--;
			deg[i]--;
			g[i][b[j].second] = 1;
		}
	}
	//for (int i = 1; i <= m; i++) cout << rm[i]; cout << endl;
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++)
			g[i][j] = 1 - g[j][i];
	for (int i = 1; i <= m; i++){
		int ret = 0;
		for (int j = 1; j <= m; j++){
			printf("%d", g[i][j]);
			ret += g[i][j];
		}
		assert(st.find(ret) != st.end());
		puts("");
	}
	return 1;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		st.insert(a[i]);
	}
	sort(a, a + n);
	
	for (int m = n; m < 80; m++){
		if (gao(m))
			return ;
	}
	puts("=(");
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