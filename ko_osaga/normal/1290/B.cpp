#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

int n;
char str[MAXN];
int low[MAXN];
int cnt[MAXN][26];

int main(){
	cin >> str;
	n = strlen(str);
	low[n] = n;
	for(int i=n-1; i>=0; i--){
		cnt[i][str[i] - 'a']++;
		for(int j=0; j<26; j++) cnt[i][j] += cnt[i+1][j];
	}
	int q; scanf("%d",&q);
	while(q--){
		int l, r; scanf("%d %d",&l,&r);
		l--, r--;
		if(l == r) puts("Yes");
		else{
			int occ = 0;
			for(int i=0; i<26; i++){
				if(cnt[l][i] != cnt[r+1][i]) occ++;
			}
			if(occ <= 2 && str[l] == str[r]){
				puts("No");
			}
			else puts("Yes");
		}
	}
}