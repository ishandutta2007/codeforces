#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, a, b;
bool tag[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		/*if(a == b){
			printf("%d\n", a);
			for(int i = 0;i <= a;i++) printf("%d ", 2 * i);puts("");
			continue;
		}*/
		if(a < b) swap(a, b);
		for(int i = 0;i <= a + b;i++) tag[i] = false;
		for(int i = (a - b) / 2;i <= 2 * b + (a - b + 1) / 2;i += 2) tag[i] = tag[a + b - i] = true;
		v.clear();
		for(int i = 0;i <= a + b;i++) if(tag[i]) v.push_back(i);
		printf("%d\n", v.size());
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
	}
}