#include <bits/stdc++.h>
#define maxn 100086

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

int main(){
	scanf("%d", &n);
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
}