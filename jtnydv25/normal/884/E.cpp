#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = (1 << 26);
bitset<N> present;	
int n, m;
inline int node(int a, int b){
	return (a << 14) + b;
}

int par[1 << 14];

int root(int x){
	return par[x] == x ? x : (par[x] = root(par[x]));
}

void merge(int x, int y){
	x = root(x), y = root(y);
	if(x > y) swap(x, y);
	if(x != y) par[x] = y;
}

char s[1 << 14];

inline int get(char x){
	if(x >= 'A') return x - 'A' + 10;
	return x - '0';

}

bool valid1[1 << 12], valid2[1 << 12];
void load(int j){
	memcpy(valid2, valid1, sizeof valid1);
	for(int i = 0; i < n; i++)
		valid1[i] = present[node(i, j)];
}

int main(){
	int v, ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j += 4){
			v = get(s[j >> 2]);
			for(int k = j + 3; k >= j; k--){
				present[node(i, k)] = v & 1;
				v >>= 1;
			}
		}
	}
	for(int i = 0; i < 2 * n; i++)
		par[i] = i;

	for(int j = 0; j < m; j++){
		load(j);
		if(j){
			for(int i = 0; i < n; i++){
				par[i] = root(par[i + n]) - n;
				par[n + i] = n + i;
			}
		}
		for(int i = 0; i < n; i++){
			if(!valid1[i])
				continue;
			if(i < n - 1 && valid1[i + 1]){
				merge(n + i, n + i + 1);
			}
			if(j != 0 && valid2[i]){
				merge(n + i, i);
			}
		}

		if(j){
			for(int i = 0; i < n; i++)
				if(par[i] == i && valid2[i]){
					ans++;
				}
		}
	}

	for(int i = 0; i < n; i++){
		if(par[n + i] == n + i && present[node(i, m - 1)]){
			ans++;
		}
	}

	printf("%d\n", ans);
}