#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
pair<int, int> a[maxn];
mt19937 mt(time(0));
int x, y, z;


int main(){
	scanf("%d", &n);
	for(int i = 1;i < (1 << n);i++) a[i].second = i;
	uniform_int_distribution<int> id(1, (1 << n) - 1);
	for(int i = 1;i <= 420;i++){
		x = id(mt), y = id(mt), z = id(mt);
		if(x == y || y == z || x == z){
			i--;
			continue;
		}
		printf("? %d %d %d\n", x, y, z);
		fflush(stdout);
		scanf("%d", &x), a[x].first++;
	}
	sort(a + 1, a + (1 << n), greater<pair<int, int> >());
	x = a[1].second, y = a[2].second;
	for(int i = 1;i < (1 << n);i++){
		if(x == i || y == i) continue;
		printf("? %d %d %d\n", x ,y, i);
		fflush(stdout);
		scanf("%d", &z);
		if(x == z || y == z) continue;
		printf("! %d\n", z);
		return 0;
	}
}