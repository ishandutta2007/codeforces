#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int l = 1, r = n, mid;
		while(l < r){
			mid = l + r >> 1;
			printf("? %d %d\n", 1, mid), fflush(stdout);
			int cnt = 0;
			for(int i = 1;i <= mid;i++){
				int x;
				scanf("%d", &x);
				if(x <= mid) cnt ^= 1;
			}
			if(cnt & 1) r = mid;
			else l = mid + 1;
		}
		printf("! %d\n", l), fflush(stdout);
	}
}