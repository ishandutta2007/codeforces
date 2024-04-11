#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
using lint = long long;
using pi = pair<int, int>;

int n;
int cnt[3];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x); cnt[x]++;
	}
	if(cnt[1] == 0){
		for(int i=1; i<=n; i++) printf("2 ");
		return 0;
	}
	if(cnt[2] == 0){
		for(int i=1; i<=n; i++) printf("1 ");
		return 0;
	}
	printf("2 1 ");
	for(int i=1; i<cnt[2]; i++) printf("2 ");
	for(int i=1; i<cnt[1]; i++) printf("1 ");
}