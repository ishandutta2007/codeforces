#include <cstdio>
#include <ios>

struct Data {
	bool tag;
	int x;
} a[210];

int n, m, ans, cnt[110];

bool Check() {
	for(int i=0; i<m; i++)
		if(a[i].x != a[i+1].x) return false;
	return true;
}

int main() {
	scanf("%d", &m);
	n = m << 1;
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i].x);
		a[i].tag = false;
	}
	
	for(int i=0; i<n; i++) {
		if(a[i].tag) continue ;
		a[i].tag = true;
		if(++ cnt[ a[i].x ] == 2) {
			int p = i;
			while(p && a[p-1].x != a[p].x) {
				std :: swap(a[p-1], a[p]);
				p --;
				ans ++;
			}
		}
		if(Check()) break;
	}
	
	printf("%d\n", ans);
	return 0;
}