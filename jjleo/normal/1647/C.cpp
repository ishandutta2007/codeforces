#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t, n, m;
char a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", a[i] + 1);
		if(a[1][1] == '1'){
			puts("-1");
			continue;
		}
		vector<tuple<int, int, int, int> > v;
		for(int i = n;i;i--) for(int j = m;j > 1;j--) if(a[i][j] == '1'){
			v.push_back(make_tuple(i, j - 1, i, j));
		}
		for(int i = n;i > 1;i--) if(a[i][1] == '1') v.push_back(make_tuple(i - 1, 1, i, 1));
		printf("%d\n", v.size());
		for(auto x : v) printf("%d %d %d %d\n", get<0>(x), get<1>(x), get<2>(x), get<3>(x));
	}
}