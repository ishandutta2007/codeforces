#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, q;
set<int> S[3];
int a[maxn];
int sk[2][maxn], top[2];//0  1  
int st[2][maxn][25], id[2][maxn][25], ans[2][maxn][3];//debug:id  
int lg[maxn], pw[25];

int l, r, mid, x, y, z;
set<int>::iterator it;
int cnt[maxn];//debug: insertset 

int main(){
	scanf("%d%d", &n, &q);
	for(register int i = 1;i <= n;i++){
		scanf("%d", &a[i]), st[0][i][0] = st[1][i][0] = n + 1, id[0][i][0] = id[1][i][0] = i;
		S[0].insert(i), S[1].insert(i), S[2].insert(i);
	}
	for(register int i = n;i;i--){
		while(top[0] && a[sk[0][top[0]]] < a[i]){
			S[0].insert(sk[0][top[0]]), --cnt[sk[0][top[0]]];
			if(!cnt[sk[0][top[0]]]) S[2].insert(sk[0][top[0]]);
			--top[0];
		}
		while(top[1] && a[sk[1][top[1]]] > a[i]){
			S[1].insert(sk[1][top[1]]), --cnt[sk[1][top[1]]];
			if(!cnt[sk[1][top[1]]]) S[2].insert(sk[1][top[1]]);
			--top[1];
		}
		
		//debug: 
		l = 1, r = top[0];
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(a[sk[0][mid]] != a[i]) l = mid;
			else r = mid - 1;
		}
		y = l;
		
		l = 1, r = top[1];
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(a[sk[1][mid]] != a[i]) l = mid;
			else r = mid - 1;
		}
		z = l;
		
		if(top[0] && a[sk[0][y]] != a[i] && (it = S[0].upper_bound(sk[0][y])) != S[0].end()){
			x = *it;
			if(x < st[0][i][0]){
				st[0][i][0] = x;
				l = 1, r = top[0];
				while(l < r){
					mid = l + r >> 1;
					if(sk[0][mid] < x) r = mid;//debug: 
					else l = mid + 1;
				}
				ans[0][i][0] = sk[0][l], ans[0][i][1] = x;
				//debug:ansl sk[] 
			}
		}
			
		
		if(top[1] && a[sk[1][z]] != a[i] && (it = S[1].upper_bound(sk[1][z])) != S[1].end()){
			x = *it;
			if(x < st[0][i][0]){
				st[0][i][0] = x;
				l = 1, r = top[1];
				while(l < r){
					mid = l + r >> 1;
					if(sk[1][mid] < x) r = mid;
					else l = mid + 1;
				}
				ans[0][i][0] = sk[1][l], ans[0][i][1] = x;
			}
		}
		
		if(top[0] && top[1] && a[sk[0][y]] != a[i] && a[sk[1][z]] != a[i] && (it = S[2].upper_bound(max(sk[0][y], sk[1][z]))) != S[2].end()){
			x = *it;
			//printf("%d %d %d %d %d--\n", i, x, sk[1][1], sk[1][2]);
			if(x < st[1][i][0]){
				st[1][i][0] = x;
				l = 1, r = top[0];
				while(l < r){
					mid = l + r >> 1;
					if(sk[0][mid] < x) r = mid;
					else l = mid + 1;
				}
				ans[1][i][0] = sk[0][l];
				
				l = 1, r = top[1];
				while(l < r){
					mid = l + r >> 1;
					if(sk[1][mid] < x) r = mid;
					else l = mid + 1;
				}
				ans[1][i][1] = sk[1][l];
				
				if(ans[1][i][0] > ans[1][i][1]) swap(ans[1][i][0], ans[1][i][1]);
				ans[1][i][2] = x;
			}
		}
		
		sk[0][++top[0]] = sk[1][++top[1]] = i;
		S[0].erase(i), S[1].erase(i), S[2].erase(i);
		cnt[i] = 2;
	}
	pw[0] = 1;for(register int i = 1;i <= 20;i++) pw[i] = pw[i - 1] << 1;
	for(register int i = 2;i <= n;i++) lg[i] = lg[i - 1] + (1 << (lg[i - 1] + 1) == i);
	//for(register int i = 1;i <= n;i++) printf("%d %d %d--\n", i, st[0][i][0], st[1][i][0]);
	for(register int j = 1;j <= 20;j++){//debug:  
		for(register int i = 1;i <= n;i++){
			if(i + pw[j] - 1 <= n){//debug:pw[j]pw[j - 1] 
				st[0][i][j] = min(st[0][i][j - 1], st[0][i + pw[j - 1]][j - 1]);
				id[0][i][j] = st[0][i][j] == st[0][i][j - 1] ? id[0][i][j - 1] : id[0][i + pw[j - 1]][j - 1];
				st[1][i][j] = min(st[1][i][j - 1], st[1][i + pw[j - 1]][j - 1]);
				id[1][i][j] = st[1][i][j] == st[1][i][j - 1] ? id[1][i][j - 1] : id[1][i + pw[j - 1]][j - 1];
			}
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d", &l, &r);
		/*if(n == 199985){
			if(i == 797){
				//for(int j = l;j <= r;j++) printf("%d ", a[j]);
				if(min(st[1][l][lg[r - l + 1]], st[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]]) <= r){
			x = st[1][l][lg[r - l + 1]] < st[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]] ? id[1][l][lg[r - l + 1]] : id[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]];
			printf("4\n%d %d %d %d\n", x, ans[1][x][0], ans[1][x][1], ans[1][x][2]);
			continue;
		}
		if(min(st[0][l][lg[r - l + 1]], st[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]]) <= r){
			x = st[0][l][lg[r - l + 1]] < st[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]] ? id[0][l][lg[r - l + 1]] : id[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]];
			printf("3\n%d %d %d\n", x, ans[0][x][0], ans[0][x][1]);
			continue;
		}
		puts("0");puts("");
				return 0;
			}
			continue;
		}*/
		
		if(min(st[1][l][lg[r - l + 1]], st[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]]) <= r){
			x = st[1][l][lg[r - l + 1]] < st[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]] ? id[1][l][lg[r - l + 1]] : id[1][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]];
			printf("4\n%d %d %d %d\n", x, ans[1][x][0], ans[1][x][1], ans[1][x][2]);
			continue;
		}
		if(min(st[0][l][lg[r - l + 1]], st[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]]) <= r){
			x = st[0][l][lg[r - l + 1]] < st[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]] ? id[0][l][lg[r - l + 1]] : id[0][r - pw[lg[r - l + 1]] + 1][lg[r - l + 1]];
			printf("3\n%d %d %d\n", x, ans[0][x][0], ans[0][x][1]);
			continue;
		}
		puts("0");puts("");
	}
}