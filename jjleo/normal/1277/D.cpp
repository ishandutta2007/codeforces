#include <bits/stdc++.h>
#define maxn 4000086

using namespace std;

int t;
int n;
char s[maxn];
vector<int> a[2][2], b[2][2];
map<string, int> mp;
string S, SS;

int main(){
	scanf("%d", &t);
	while(t--){
		mp.clear();
		scanf("%d", &n);
		for(int i = 0;i <= 1;i++) for(int j = 0;j <= 1;j++) a[i][j].clear(), b[i][j].clear();
		for(int i = 1;i <= n;i++){
			scanf("%s", s), S = SS = s;
			reverse(SS.begin(), SS.end());
			if(mp[SS]){
				a[S[0] - '0'][S[S.length() - 1] - '0'].push_back(i);
				a[SS[0] - '0'][SS[SS.length() - 1] - '0'].push_back(mp[SS]);
				//printf("%d %d--\n", S[0] - '0', S[S.length() - 1] - '0');
				mp.erase(SS);
			}else{
				mp[S] = i;
			}
		}
		for(map<string, int>::iterator it = mp.begin();it != mp.end();++it){
			if(!(it->second)) continue;
			//printf("%d--\n", it->second);
			b[(it->first)[0] - '0'][(it->first)[(it->first).length() - 1] - '0'].push_back(it->second);
		}
		if((a[0][0].size() || b[0][0].size()) && (a[1][1].size() || b[1][1].size()) && !a[0][1].size() && !a[1][0].size() && !b[0][1].size() && !b[1][0].size()){
			puts("-1");
			continue;
		}
		if(abs((int)a[0][1].size() - (int)a[1][0].size()) > b[0][1].size() + b[1][0].size() + 1){
			puts("-1");
			continue;
		}
		/*if(!a[0][1].size() && !a[1][0].size() && !b[0][1].size() && !b[1][0].size()){
			if(b[0][0].size() < b[1][1].size()){
				printf("%d\n", b[0][0].size());
				for(int i = 0;i < b[0][0].size();i++) printf("%d ", b[0][0][i]);
				puts("");
			}else{
				printf("%d\n", b[1][1].size());
				for(int i = 0;i < b[1][1].size();i++) printf("%d ", b[1][1][i]);
				puts("");
			} 
			continue;
		}*/
		int x = a[0][1].size() + b[0][1].size(), y = a[1][0].size() + b[1][0].size();
		//printf("%d %d--\n", x, y);
		int ans = 0;
		if(x > y){
			while(abs(x - y) > 1) x--, y++, ans++;
			printf("%d\n", ans);
			for(int i = 0;i < ans;i++) printf("%d ", b[0][1][i]);
			puts("");
		}else{
			while(abs(x - y) > 1) y--, x++, ans++;
			printf("%d\n", ans);
			for(int i = 0;i < ans;i++) printf("%d ", b[1][0][i]);
			puts("");
		}
	}
}