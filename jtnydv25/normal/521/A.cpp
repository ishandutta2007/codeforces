#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

char s[100005];
int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 0;i < n; i++){
		if(s[i] == 'A') a++;
		if(s[i] == 'C') b++;
		if(s[i] == 'G') c ++;
		if(s[i] == 'T') d ++;
	}

	int mx = max(a, max(b, max(c, d)));
	int cnt = 0;
	if(a == mx) cnt++;
	if(b == mx) cnt++;
	if(c == mx) cnt++;
	if(d == mx) cnt++;

	int ans = 1;
	for(int i = 1; i <= n; i++){
		ans = (ans * 1ll * cnt) % (1000000007);
	}
	printf("%d\n", ans);
}