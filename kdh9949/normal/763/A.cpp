#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, c[100010], chk[100010];
int p[100010];
vector<int> e[100010];
int nd[100010];

int fnd(int x){ if(p[x] == x) return x; p[x] = fnd(p[x]); return p[x]; }
void uni(int x, int y){ p[fnd(x)] = fnd(y); }

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
		int x, y; scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
		scanf("%d", c + i);
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++){
		for(auto &j : e[i]){
			if(c[i] == c[j]) uni(i, j);
		}
    }
    int cs = 0;
    for(int i = 1; i <= n; i++) chk[fnd(i)] = 1;
    for(int i = 1; i <= n; i++) cs += chk[i];
    fill(chk, chk + n + 1, 0);
    for(int i = 1; i <= n; i++){
		int ccs = 1;
		chk[fnd(i)] = i;
		for(auto &j : e[i]){
			if(c[j] != c[i]){
				if(chk[fnd(j)] != i){
					ccs++;
					chk[fnd(j)] = i;
				}
			}
		}
		if(cs == ccs){
			printf("YES\n%d\n", i);
			return 0;
		}
    }
    puts("NO");
	return 0;
}