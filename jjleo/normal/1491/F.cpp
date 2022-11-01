#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x, y;
vector<int> ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans.clear();
		for(int i = 2;;i++){
			printf("? %d %d\n", i - 1, 1), fflush(stdout);
			for(int j = 1;j < i;j++) printf("%d ", j);
			puts(""), fflush(stdout);
			printf("%d\n", i), fflush(stdout);
			scanf("%d", &y);
			if(y){
				x = i;
				break;
			}
		}
		int l = 1, r = x - 1, mid;
		while(l < r){
			mid = l + r >> 1;
			printf("? %d %d\n", mid, 1), fflush(stdout);
			for(int j = 1;j <= mid;j++) printf("%d ", j);
			puts(""), fflush(stdout);
			printf("%d\n", x), fflush(stdout);
			scanf("%d", &y);
			if(y) r = mid;
			else l = mid + 1;
		}
		for(int i = 1;i < x;i++){
			if(i ^ l) ans.push_back(i);
		}
		for(int i = x + 1;i <= n;i++){
			printf("? %d %d\n", 1, 1), fflush(stdout);
			printf("%d\n", i), fflush(stdout);
			printf("%d\n", x), fflush(stdout);
			scanf("%d", &y);
			if(!y) ans.push_back(i);
		} 
		printf("! %d", ans.size());
		for(int i = 0;i < ans.size();i++) printf(" %d", ans[i]);
		puts(""), fflush(stdout);
	}
}