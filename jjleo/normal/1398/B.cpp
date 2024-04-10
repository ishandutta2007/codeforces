#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		v.clear();
		int x = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0'){
				if(x) v.push_back(x);
				x = 0;
			}else{
				x++;
			}
		}
		if(x) v.push_back(x);
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for(int i = 0;i < v.size();i++){
			if(!(i & 1)) ans += v[i];
		}
		printf("%d\n", ans);
	}
}