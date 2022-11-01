#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

inline int query(int l, int r){
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
} 

int main(){
	scanf("%d", &n);
	int x = query(1, n);
	if(x > 1 && query(1, x) == x){
		int l = 1, r = x - 1, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(query(mid, x) == x) l = mid;
			else r = mid - 1;
		}
		printf("! %d\n", l);
	}else{
		int l = x + 1, r = n, mid;
		while(l < r){
			mid = l + r >> 1;
			if(query(x, mid) == x) r = mid;
			else l = mid + 1;
		}
		printf("! %d\n", l);
	}
}