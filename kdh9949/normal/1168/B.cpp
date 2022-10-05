#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300005;

int n, a[N];
ll r;
char s[N];

int chk(int x, int y){
	for(int i = x; i <= y; i++){
		for(int j = 1; i + 2 * j <= y; j++){
			if(a[i] == a[i + j] && a[i + j] == a[i + 2 * j]) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++) a[i] = (s[i] == '1');
	for(int i = 0; i < n; i++){
		for(int j = 3; i + j - 1 < n; j++){
			if(chk(i, i + j - 1)){
				r += (n - (i + j - 1));
				break;
			}
		}
	}
	printf("%lld\n", r);
}