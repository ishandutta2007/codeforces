#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		int x = n;
		int cnt = 0;
		while(x % d == 0) x /= d, cnt++;
		if(cnt == 1){
			puts("NO");
			continue;
		}
		bool tag = false;
		for(int i = 2;i * i <= x;i++) if(x % i == 0){
			tag = true;
			break;
		}
		if(tag){
			puts("YES");
			continue;
		}
		int p;
		for(int i = 2;i * i <= d;i++) if(d % i == 0){
			tag = true;
			p = i;
			break;
		}
		if(cnt == 2) tag = false;
		if(tag){
			int tot = 0;
			while(d % p == 0) d /= p, tot++;
			if(d == 1 && p == x){
				if(cnt == 3 && tot == 2) tag = false;
			}
		}
		puts(tag ? "YES" : "NO");
	}
}