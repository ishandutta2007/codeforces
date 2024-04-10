#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int t;
int n, m;

map<pair<pair<int, int>, pair<int, int> >, bool> mp;
int a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		mp.clear();
		bool tag = false;
		while(n--){
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(b == c) tag = true;
		}
		puts(tag && m % 2 == 0 ? "YES" : "NO");
	} 
}