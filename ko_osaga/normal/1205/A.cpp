#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 200005;

int n, a[MAXN];

int main(){
	cin >> n;
	if(n & 1){
		puts("YES");
		for(int i=0; i<n; i++){
			a[i] = 2 * i + 1;
			a[i + n] = 2 * i + 2;
			if(i % 2) swap(a[i], a[i + n]);
		}
		for(int i=0; i<2*n; i++) printf("%d ", a[i]);
	}
	else puts("NO");
}