#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

char s[maxn];
int n;
bool del[maxn];

string S;
pair<int, string> ans[maxn];


int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int x = 0, y = 0, z = 0;
	for(int i = n;i;i--){
		if(i < n && !del[i + 1] && s[i] == s[i + 1] && (s[i] > x || (s[i] == x && s[i] > y))){
			S.pop_back();
			del[i] = true;
			if(S.back() == y) x = y, y = z, z = 0;
		}else{
			if(S.empty() || S.back() != s[i]){
				z = y, y = x, x = s[i];
			}
			S += s[i];
		}
		ans[i].first = S.length();
		if(S.length() <= 10) ans[i].second = S, reverse(ans[i].second.begin(), ans[i].second.end());
		else{
			for(int j = 1;j <= 5;j++) ans[i].second += S[S.length() - j];
			ans[i].second += "...";
			ans[i].second += S[1], ans[i].second += S[0];
		}
	}
	for(int i = 1;i <= n;i++) printf("%d %s\n", ans[i].first, ans[i].second.c_str());
}