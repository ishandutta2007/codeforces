#include <bits/stdc++.h>
#define maxn 250086

using namespace std;

int n, m;
int a[maxn];

int id(int x, int y){
	return (x - 1) * m + y;
}

int cnt = 2;

void dfs(int i){
	if(i > n){
		for(int j = 2;j <= n;j++){
			int num = 0;
			for(int k = 1;k <= m;k++) num += a[id(1, k)] != a[id(j, k)];
			if(num > 2) return;
		}
		puts("Yes");
		for(int j = 1;j <= m;j++) printf("%d ", a[id(1, j)]);
		exit(0);
	}
	vector<int> v;
	for(int j = 1;j <= m;j++){
		if(a[id(i, j)] ^ a[id(1, j)]){
			v.push_back(j);
			if((int)v.size() - 2 > cnt) return;
		}
	}
	if(v.size() <= 2){
		dfs(i + 1);
		return;
	}
	if(v.size() == 3){
		for(int j = 0;j < 3;j++){
			int x = a[id(i, v[j])];
			swap(x, a[id(1, v[j])]);
			cnt--;
			dfs(i + 1);
			cnt++;
			swap(x, a[id(1, v[j])]);
		}
	}else{
		for(int j = 0;j < 4;j++){
			for(int k = j + 1;k < 4;k++){
				int x = a[id(i, v[j])], y = a[id(i, v[k])];
				swap(x, a[id(1, v[j])]), swap(y, a[id(1, v[k])]);
				cnt -= 2;
				dfs(i + 1);
				cnt += 2;
				swap(x, a[id(1, v[j])]), swap(y, a[id(1, v[k])]);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[id(i, j)]);
	dfs(2);
	printf("No");
}