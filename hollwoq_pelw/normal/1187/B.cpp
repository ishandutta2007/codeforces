#include <bits/stdc++.h>
using namespace std;

const int N=201000;
char s[N],t[N];
int n,cnt[30],q;
vector<int> pos[30];
 
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		pos[s[i]-'a'].push_back(i);
	}
	cin >> q;
	while (q--) {
		cin >> t;
		int m=strlen(t);
		for(int i = 0; i < 26; i++) cnt[i]=0;
		for(int i = 0; i < m; i++) cnt[t[i]-'a']++;
		int ans=-1;
		for(int i = 0; i < 26; i++) if (cnt[i]) ans=max(ans,pos[i][cnt[i]-1]);
		cout << ans+1 << endl;
	}
}