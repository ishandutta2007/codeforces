#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n;
char s[maxn];
string S;
multiset<string> st;

vector<string> v;

inline bool cmp(string a, string b){
	return a.length() < b.length();
}

int cnt[26];
char ans[maxn];
int f[maxn][26];

int main(){
	scanf("%d", &n);
	if(n <= 3){
		if(n == 1){
			printf("? 1 1\n"), fflush(stdout);
			scanf("%s", s);
			printf("! %s\n", s);
			return 0;
		}
		printf("? 2 %d\n", n), fflush(stdout);
		for(int i = 1;i <= n * (n - 1) / 2;i++){
			scanf("%s", s);
			S = s;
			sort(S.begin(), S.end());
			st.insert(S);
		}
		printf("? 1 %d\n", n), fflush(stdout);
		for(int i = 1;i <= n * (n + 1) / 2;i++){
			scanf("%s", s);
			S = s;
			sort(S.begin(), S.end());
			if(st.find(S) == st.end()) v.push_back(S);
			else st.erase(st.find(S));
		}
		sort(v.begin(), v.end(), cmp);
		printf("! ");
		for(int i = 0;i < n;i++){
			if(i == 0){
				printf("%c", v[i][0]);
				continue;
			}
			for(int j = 0;j < i + 1;j++) cnt[v[i][j] - 'a']++;
			for(int j = 0;j < i;j++) cnt[v[i - 1][j] - 'a']--;
			for(int j = 0;j < 26;j++){
				if(cnt[j]){
					cnt[j] = 0, printf("%c", j + 'a');
					break;
				}
			}
		}
		puts("");
		return 0;
	}
	int m = (n + 1) / 2;
	printf("? 2 %d\n", m), fflush(stdout);
	for(int i = 1;i <= m * (m - 1) / 2;i++){
		scanf("%s", s);
		S = s;
		sort(S.begin(), S.end());
		st.insert(S);
	}
	printf("? 1 %d\n", m), fflush(stdout);
	for(int i = 1;i <= m * (m + 1) / 2;i++){
		scanf("%s", s);
		S = s;
		sort(S.begin(), S.end());
		if(st.find(S) == st.end()) v.push_back(S);
		else st.erase(st.find(S));
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0;i < m;i++){
		if(i == 0){
			ans[i + 1] = v[i][0];
			continue;
		}
		for(int j = 0;j < i + 1;j++) cnt[v[i][j] - 'a']++;
		for(int j = 0;j < i;j++) cnt[v[i - 1][j] - 'a']--;
		for(int j = 0;j < 26;j++){
			if(cnt[j]){
				cnt[j] = 0, ans[i + 1] = j + 'a';
				break;
			}
		}
	}
	printf("? 1 %d\n", n), fflush(stdout);
	for(int i = 1;i <= n * (n + 1) / 2;i++){
		scanf("%s", s);
		int len = strlen(s);
		for(int j = 0;j < len;j++){
			f[len][s[j] - 'a']++;
		}
	}
	for(int i = m;i;i--){
		for(int j = 0;j < 26;j++){
			int x = f[i][j] - f[i - 1][j];
			for(int k = i;k < n + 1 - i;k++) x -= ans[k] == j + 'a';
			if(x){
				ans[n + 1 - i] = j + 'a';
				break;
			}
		}
	}
	printf("! ");
	for(int i = 1;i <= n;i++) printf("%c", ans[i]);
	puts("");
	
}