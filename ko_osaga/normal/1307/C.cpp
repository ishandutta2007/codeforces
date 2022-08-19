#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 300005;

int n;
char str[MAXN];

int main(){
	scanf("%s", str);
	n = strlen(str);
	lint ret = 0;
	for(int i='a'; i<='z'; i++){
		ret = max(ret, 1ll * count(str, str + n, i));
	}
	int tab[26] = {};
	lint cnt[26][26] = {};
	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++){
			cnt[j][str[i] - 'a'] += tab[j];
		}
		tab[str[i] - 'a']++;
	}
	for(int i=0; i<26; i++){
		for(int j=0; j<26; j++) ret = max(ret, cnt[i][j]);
	}
	cout << ret << endl;
}