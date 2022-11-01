#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m;
pair<int, int> a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d%d", &a[i].second, &a[i].first);
		if(m & 1){
			puts("NO");
			continue;
		}
		sort(a + 1, a + 1 + m);
		int x = 1, y = 0;
		bool tag = false;
		for(int i = 1;i <= m;i++){
			if(i < m && a[i + 1].first == a[i].first){
				if(y){
					tag = true;
					break;
				}
				i++;
				x = a[i].first + 1;
				continue;
			}
			if(!y){
				y = a[i].second;
				x = a[i].first + 1;
				continue;
			}
			if(y != a[i].second){
				if(!((a[i].first - x) & 1)){
					tag = true;
					break;
				}
				y = 0;
				x = a[i].first + 1;
			}else{
				if((a[i].first - x) & 1){
					tag = true;
					break;
				}
				y = 0;
				x = a[i].first + 1;
			}
		}
		puts(tag ? "NO" : "YES");
	}
}