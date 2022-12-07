#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[2][maxn];
bool del[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%s", &n, s[0] + 1, s[1] + 1);
		int ans = 0;
		vector<int> v;
		for(int I = 1;I <= n;I++){
			if(s[0][I] ^ s[1][I]){
				for(int i = 0;i < v.size();i++) del[i] = false;
				for(int i = 0;i < v.size();i++){
					if(v[i] == 0){
						if(i > 0 && v[i - 1] == 1 && !del[i - 1]) ans += 2;
						else if(i + 1 < v.size() && v[i + 1] == 1) ans += 2, del[i + 1] = true;
						else ans++;
					}
				}
				v.clear();
				ans += 2;
			}
			else v.push_back(s[0][I] - '0');
		}
		for(int i = 0;i < v.size();i++) del[i] = false;
		for(int i = 0;i < v.size();i++){
			if(v[i] == 0){
				if(i > 0 && v[i - 1] == 1 && !del[i - 1]) ans += 2;
				else if(i + 1 < v.size() && v[i + 1] == 1) ans += 2, del[i + 1] = true;
				else ans++;
			}
		}
		printf("%d\n", ans);
	} 
}