#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int l, r;

struct Edge{
	int a, b, c;
};
vector<Edge> ans;

int a[maxn], cnt = 1;

int main(){
	scanf("%d%d", &l, &r);
	if(l == r){
		printf("YES\n2 1\n1 2 %d", l);
		return 0;
	}
	int val = r - l;
	int I = 20;
	while(1){
		if((1 << I) & val) break;
		I--;
	}
	for(int i = I;~i;i--) a[i] = ++cnt;
	int x = 0;
	for(int i = I;~i;i--){
		if(!((1 << i) & val)) continue;
		ans.push_back((Edge){1, a[i], x ? x : 1});
		x += 1 << i;
	}
	for(int i = I;~i;i--){
		for(int j = i - 1;~j;j--){
			if(i == I){
				if(j) ans.push_back((Edge){a[i], a[j], (1 << j) - 1});
				continue;	
			}
			ans.push_back((Edge){a[i], a[j], 1 << j});
		}
	} 
	ans.push_back((Edge){1, ++cnt, val});
	++cnt;
	for(int i = 1;i < cnt;i++) ans.push_back((Edge){i, cnt, l});
	printf("YES\n%d %d\n", cnt, ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
}