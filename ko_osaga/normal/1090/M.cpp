#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, k, a[MAXN], s[MAXN];

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=2; i<=n; i++){
		s[i] = s[i-1] + (a[i] == a[i-1]);
	}
	int ptr = 1, ret = 0;
	for(int i=1; i<=n; i++){
		while(s[ptr] != s[i]) ptr++;
		ret = max(i - ptr + 1, ret);
	}
	cout << ret << endl;
}