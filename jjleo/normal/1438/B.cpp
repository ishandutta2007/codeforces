#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
map<int, int> mp;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		bool tag = false;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x), mp[x]++;
			if(mp[x] > 1) tag = true;
		}
		puts(tag ? "YES" : "NO");
	} 
}