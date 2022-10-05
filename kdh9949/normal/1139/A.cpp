#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 65005;

char s[N];
ll r;

int main(){
	scanf("%*d%s", s + 1);
	for(int i = 1; s[i]; i++) if(s[i] % 2 == 0) r += i;
	printf("%lld\n", r);
}