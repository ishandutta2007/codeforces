#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 300005;
const int mod = 1e9 + 7;
int chk[MAXN];

int main(){
	int n;
	cin >> n;
	int pos = n+1;
	printf("1 ");
	for(int i=2; i<=n+1; i++){
		int x;
		scanf("%d",&x);
		chk[x] = 1;
		while(chk[pos-1]) pos--;
		printf("%d ", i - (n + 1 - pos));
	}
}