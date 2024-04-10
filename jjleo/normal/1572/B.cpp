#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, a[maxn];
vector<int> v;

void solve(int l, int r){
	for(int i = l;i < r;i += 2) v.push_back(i);
	for(int i = r - 4;i >= l;i -= 2) v.push_back(i);
} 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum ^= a[i];
		if(sum){
			puts("NO");
			continue;
		}
		bool tag = false;
		v.clear();
		if(n & 1) solve(1, n), tag = true;
		else{
			sum = 0;
			for(int i = 1;i <= n;i++){
				sum ^= a[i];
				if((i & 1) && !sum){
					tag = true;
					solve(1, i), solve(i + 1, n);
					break;
				}
			}
		}
		if(!tag) puts("NO");
		else{
			printf("YES\n%d\n", v.size());
			for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
		}
	}
}