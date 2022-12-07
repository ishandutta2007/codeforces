#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int x;
int a[maxn];
int get(int x){
	if(a[x]) return a[x];
	printf("? %d\n", x);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

int main(){
	scanf("%d", &n);
	a[0] = a[n + 1] = n + 1;
	int l = 0, r = n + 1, mid;
	while(l < r){
		mid = l + r >> 1;
		a[mid] = get(mid), a[mid - 1] = get(mid - 1), a[mid + 1] = get(mid + 1);
		if(a[mid] < a[mid - 1] && a[mid] < a[mid + 1]) return printf("! %d\n", mid), 0;
		if(a[mid] > a[mid - 1]) r = mid;
		else l = mid + 1;
	}
	printf("! %d\n", l);
}