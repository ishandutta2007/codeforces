#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;

int n;
lint cnt1[505][505], cnt2[500005];
int a[500005];

void Do(int x, int y){
	if(x <= 0 || x > 500000) return;
	cnt2[x] += y;
	for(int i=1; i<=500; i++){
		cnt1[i][x % i] += y;
	}
}

int main(){
	scanf("%d",&n);
	while(n--){
		int t; scanf("%d",&t);
		if(t == 1){
			int x, y; scanf("%d %d",&x,&y);
			Do(x, -a[x]);
			a[x] += y;
			Do(x, a[x]);
		}
		else{
			int x, y; scanf("%d %d",&x,&y);
			if(x <= 500) printf("%lld\n", cnt1[x][y]);
			else{
				lint ret = 0;
				for(int i=y; i<=500000; i+=x) ret += cnt2[i];
				printf("%lld\n", ret);
			}
		}
	}
}