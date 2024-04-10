#include <bits/stdc++.h>
#define maxn 100086
#define maxm 320
using namespace std;

int f[maxm][maxn];
int n, sn;
int opt, l, r, k;
int m, x;
deque<int> q[maxm];
int lastans;

int main(){
	scanf("%d", &n), sn = (int)sqrt(n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		int ii = (i - 1) / sn;
		q[ii].push_back(x), ++f[ii][x];
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &l, &r);
			l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1;
			if(l > r) swap(l, r);
			int ll = (l - 1) / sn, rr = (r - 1) / sn, li = (l - 1) % sn, ri = (r - 1) % sn;
			//printf("%d %d %d %d--\n", ll, rr, li, ri);
			if(ll == rr){
				int x = q[ll][ri];
				q[ll].erase(q[ll].begin() + ri);
				q[ll].insert(q[ll].begin() + li, x);
			}else{
				int x = q[ll].back();q[ll].pop_back(), --f[ll][x];
				for(int i = ll + 1;i < rr;i++){
					q[i].push_front(x), ++f[i][x];
					x = q[i].back(), q[i].pop_back(), --f[i][x];
				}
				q[rr].push_front(x), ++f[rr][x];
				x = q[rr][ri + 1], --f[rr][x], q[rr].erase(q[rr].begin() + ri + 1);//debug:pushfront+1 
				++f[ll][x], q[ll].insert(q[ll].begin() + li, x);
			}
		}else{
			scanf("%d%d%d", &l, &r, &k);
			l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1, k = (k + lastans - 1) % n + 1;
			if(l > r) swap(l, r);
			int ll = (l - 1) / sn, rr = (r - 1) / sn, li = (l - 1) % sn, ri = (r - 1) % sn;
			int ans = 0;
			if(ll == rr){
				for(int i = li;i <= ri;i++) ans += q[ll][i] == k; 
			}else{
				for(int i = ll + 1;i < rr;i++) ans += f[i][k];
				//printf("%d %d %d %d--\n", ll, rr, li, ri);
				for(int i = li;i < sn;i++) ans += q[ll][i] == k; 
				for(int i = 0;i <= ri;i++) ans += q[rr][i] == k; 
			}
			printf("%d\n", lastans = ans);
		}
	}
}