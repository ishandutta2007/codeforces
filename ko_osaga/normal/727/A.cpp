#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int a, b;

int f(int x){
	if(x == a) return 1;
	if(x < a) return 1e9;
	if(x % 2 == 0) return f(x/2) + 1;
	if(x % 10 == 1) return f(x/10) + 1;
	return 1e9;
}

void g(int x){
	if(x == a) return;
	if(x % 2 == 0) g(x/2);
	else g(x/10);
	printf(" %d", x);
}

int main(){
	cin >> a >> b;
	if(f(b) > 1e8){
		puts("NO");
		return 0;
	}
	printf("YES\n%d\n%d", f(b), a);
	g(b);
}