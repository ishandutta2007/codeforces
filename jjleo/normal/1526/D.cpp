#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
char s[maxn], c[5] = {0, 'A', 'T', 'O', 'N'};
int sum[5];
int p[5], P[5];
int a[maxn], b[maxn];
vector<int> v[5];

inline void add(int x, int y){
	for(;x <= n;x += x & -x) b[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += b[x];
	return sum;
}

ll cal(){
	int cnt = 0;
	for(int i = 1;i <= 4;i++) for(int j = 0;j < v[p[i]].size();j++) a[++cnt] = v[p[i]][j];
	for(int i = 1;i <= n;i++) b[i] = 0;
	ll sum = 0;
	for(int i = n;i;i--) sum += query(a[i]), add(a[i], 1);
	return sum;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 1;i <= 4;i++) p[i] = i, sum[i] = 0, v[i].clear();
		for(int i = 1;i <= n;i++){
			int x;
			switch(s[i]){
				case 'A':
					x = 1;
					break;
				case 'T':
					x = 2;
					break;
				case 'O':
					x = 3;
					break;
				case 'N':
					x = 4;
					break;			
			}
			sum[x]++, v[x].push_back(i); 
		}
		ll ans = 0;
		do{
			ll sum = cal();
			if(sum >= ans){
				ans = sum;
				for(int i = 1;i <= 4;i++) P[i] = p[i];
			}
		}while(next_permutation(p + 1, p + 5));
		for(int i = 1;i <= 4;i++){
			for(int j = 1;j <= sum[P[i]];j++) printf("%c", c[P[i]]);
		}
		puts("");
	}
}