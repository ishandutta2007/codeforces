#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int main(){
	int p, q, r;
	scanf("%d:%d", &p, &q);
	scanf("%d", &r);
	int x = p * 60 + q;
	x += r;
	x %= (60 * 24);
	printf("%02d:%02d\n", x / 60, x % 60);
	return 0;
}