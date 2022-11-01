#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		v.clear();
		for(int i = 1;i <= n;i += 2){
			if(a[i] + a[i + 1] == 1) v.push_back(0);
			else v.push_back(a[i]), v.push_back(a[i + 1]);
		}
		printf("%d\n", v.size());
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
		puts("");
	}
}