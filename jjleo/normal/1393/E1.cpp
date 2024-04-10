#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef unsigned long long ull;

const int p = 1e9 + 7, m = 131;

int n;
string ss[maxn];
char s[maxn];
vector<ull> v[maxn];
ull sum[maxn];

inline ull geth(int i, int len, int x){
	if(x > len) return v[i][len];
	ull lsum = v[i][x - 1], rsum = v[i][len + 1] - v[i][x] * sum[len + 1 - x];
	return lsum * sum[len + 1 - x] + rsum;
}

inline char getc(int i, int len, int x){
	int j =  x > len ? (len - 1) : len;
	if(j > ss[i].length()) return 0;
	return ss[i][j];
}

inline bool leq(int i, int x, int j, int y){//s_ix <= s_jy
	int lenx = x <= ss[i].length() ? (ss[i].length() - 1) : ss[i].length();
	int leny = y <= ss[j].length() ? (ss[j].length() - 1) : ss[j].length();
	int l = 0, r = min(lenx, leny), mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(geth(i, mid, x) == geth(j, mid, y)) l = mid;
		else r = mid - 1;
	}
	return getc(i, l + 1, x) <= getc(j, l + 1, y);
}

char nxt[maxn];
int sa[maxn];
vector<int> a[maxn];
int f[2][maxn];

int main(){
	sum[0] = 1;
	for(int i = 1;i < maxn;i++) sum[i] = sum[i - 1] * m;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		ss[i] = s + 1;
		int len = strlen(s + 1);
		v[i].push_back(0);
		for(int j = 1;j <= len;j++) v[i].push_back(v[i].back() * m + s[j]);
		for(int j = len;j;j--){
			if(s[j + 1] != s[j]) nxt[j] = s[j + 1];
			else nxt[j] = nxt[j + 1];
		}
		int l = 1, r = len;
		for(int j = 1;j <= len;j++){
			if(nxt[j] > s[j]) sa[r--] = j;
			else sa[l++] = j;
		}
		for(int j = 1;j <= len;j++){
			a[i].push_back(sa[j]);
			if(sa[j] == len) a[i].push_back(len + 1);
		}
	}
	for(int i = 0;i < a[1].size();i++) f[1][i] = 1;
	for(int i = 2;i <= n;i++){
		int x = -1, sum = 0;
		for(int j = 0;j < a[i].size();j++){
			while(x + 1 < a[i - 1].size() && leq(i - 1, a[i - 1][x + 1], i, a[i][j])){
				sum += f[i & 1 ^ 1][++x];
				if(sum >= p) sum -= p;
			}
			f[i & 1][j] = sum;
		}
	}
	int ans = 0;
	for(int i = 0;i < a[n].size();i++){
		ans += f[n & 1][i];
		if(ans >= p) ans -= p;
	}
	printf("%d", ans);
}