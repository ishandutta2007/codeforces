#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a;
vector<int> v[2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		v[0].clear(), v[1].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &a);
			v[a & 1].push_back(i);
		}
		if(v[0].size() == 0 && v[1].size() == 1) puts("-1");
		else {
			if(v[0].size()) printf("1\n%d\n", v[0][0]);
			else printf("2\n%d %d\n", v[1][0], v[1][1]);
		}
	}
}