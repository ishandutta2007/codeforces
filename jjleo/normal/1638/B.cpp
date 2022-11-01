#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> v[2];
		while(n--) scanf("%d", &x), v[x & 1].push_back(x);
		bool tag = false;
		for(int i = 1;i < v[0].size();i++) if(v[0][i - 1] > v[0][i]) tag = true;
		for(int i = 1;i < v[1].size();i++) if(v[1][i - 1] > v[1][i]) tag = true;
		puts(tag ? "No" : "Yes");
	}
}