#include <bits/stdc++.h>
#define maxn 100086

//316 65

using namespace std;

int n;
int p[maxn], cnt;
bool tag[maxn];
int m, x;
vector<int> v;

int main(){
	scanf("%d", &n);
	if(n == 1) return puts("C 1"), 0;
	for(int i = 2;i <= n;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i <= n;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	} 
	memset(tag, 0, sizeof(tag));
	m = n;
	bool flag = false;
	int id;
	for(int i = 1;i <= cnt;i++){
		if(!flag){
			if(p[i] * p[i] > n){
				id = i;
				break;
			}
			printf("B %d\n", p[i]), fflush(stdout);
			scanf("%d", &x);
			m -= x;
			for(int j = 1;j * p[i] <= n;j++){
				if(!tag[j * p[i]]) tag[j * p[i]] = true;
			}
			printf("B %d\n", p[i]), fflush(stdout);
			scanf("%d", &x);
			if(x){
				flag = true;
				v.push_back(p[i]); 
			}
		}else{
			printf("B %d\n", p[i]), fflush(stdout);
			scanf("%d", &x);
			int tot = 0;
			for(int j = 1;j * p[i] <= n;j++){
				if(!tag[j * p[i]]) tag[j * p[i]] = true, tot++;
			}
			if(tot < x) v.push_back(p[i]);
		}
	}
	if(!flag){
		for(int i = id;i <= cnt;i++){
			printf("B %d\n", p[i]), fflush(stdout);
			scanf("%d", &x);
			if(i % 100 == 0 || i == cnt){
				printf("A %d\n", 1), fflush(stdout);
				scanf("%d", &x);
				if(x != m - (i - id + 1)){
					for(int j = id;j <= i;j++){
						printf("A %d\n", p[j]), fflush(stdout);
						scanf("%d", &x);
						if(x){
							printf("C %d\n", p[j]);
							flag = true;
							break;
						}
					}
					if(flag) break;
				} 
				m -= i - id + 1;
				id = i + 1;
			}
		}
		if(!flag) puts("C 1");
	}else{
		int ans = 1;
		for(int i = 0;i < v.size();i++){
			ans *= v[i];
			long long j = 1ll * v[i] * v[i];
			while(j <= n){
				printf("A %lld\n", j), fflush(stdout);
				scanf("%d", &x);
				if(x) ans *= v[i];
				else break;
				j *= v[i];
			}
		}
		printf("C %d\n", ans);
	}
	
}