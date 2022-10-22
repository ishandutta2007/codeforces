#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,pre[110000][26]; vector<int> vec[26];
char s[110000],t[110000],r[110000];
bool check(char *s,char *t){
	for (int i=1;i<=n;i++)
		if (s[i]!=t[i]) return s[i]<t[i];
	return false;
}
int getval(int pos){
	int res=0;
	for (int c=0;c<26;c++)
		if (!vec[c].empty()&&vec[c].back()<=pos) res+=pre[pos-1][c]-pre[vec[c].back()-1][c];
	return res;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		if (check(s,t)){
			puts("0");
			continue;
		}
		int pos=0;
		for (int i=1;i<=n;i++)
			if (s[i]!=t[i]) break;
			else pos=i;
		for (int i=1;i<=n;i++) r[i]=s[i];
		sort(r+1,r+n+1);
		if (!check(r,t)){
			puts("-1");
			continue;
		}
		for (int i=1;i<=n;i++){
			for (int c=0;c<26;c++) pre[i][c]=pre[i-1][c];
			pre[i][s[i]-'a']++;
		}
		for (int c=0;c<26;c++) vec[c].clear();
		bool ok=false;
		for (int i=1;i<=pos;i++)
			if (s[i]>s[i+1]) ok=true;
		if (ok){
			puts("1");
			continue;
		}
		ll ans=1ll<<60;
		for (int i=pos+1;i<=n;i++)
			if (s[i]<s[pos]) ans=min(ans,(ll)i-pos);
		for (int i=n;i>=pos+1;i--)
			vec[s[i]-'a'].push_back(i);
		ll now=0;
		for (int i=pos+1;i<=n;i++){
			int pos=n+1;
			for (int c=0;c<t[i]-'a';c++)
				if (!vec[c].empty()) pos=min(pos,vec[c].back());
			if (pos!=n+1) ans=min(ans,now+getval(pos));
			
			int c=t[i]-'a';
			if (!vec[c].empty()){
				pos=vec[c].back();
				now+=getval(pos); vec[c].pop_back();
			} else break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}