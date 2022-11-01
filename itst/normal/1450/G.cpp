#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int cnt[23] , l[23] , r[23] , T , N , A , B , pos[23];
string s , alphabet = "acdefhijklmnopqsvwxz" , str , ans;
int f[1 << 20] , g[1 << 20];

int qf(int); int qg(int);
int qg(int x){
	if(~g[x]) return g[x];
	if(!x) return 1;
	int pre = 0 , suf = x;
	for(int i = 0 ; i < str.size() ; ++i)
		if(x >> i & 1){pre |= 1 << i; suf ^= 1 << i; if(qf(pre) && qg(suf)) return g[x] = 1;}
	return g[x] = 0;
}
int qf(int x){
	if(~f[x]) return f[x];
	if(!x) return 1;
	int l = 1e9 , r = 0 , c = 0;
	for(int i = 0 ; i < str.size() ; ++i)
		if(x >> i & 1){l = min(l , ::l[pos[i]]); r = max(r , ::r[pos[i]]); c += cnt[pos[i]];}
	if(1ll * c * B < 1ll * (r - l + 1) * A) return f[x] = 0;
	for(int i = 0 ; i < str.size() ; ++i) if((x >> i & 1) && qg(x ^ (1 << i))) return f[x] = 1;
	return f[x] = 0;
}

int main(){
	cin >> N >> A >> B >> s; memset(l , -1 , sizeof(l)); memset(f , -1 , sizeof(f)); memset(g , -1 , sizeof(g));
	for(int i = 0 ; i < s.size() ; ++i){
		int pos = 0; while(alphabet[pos] != s[i]){++pos;}
		if(!(cnt[pos]++)){::pos[str.size()] = pos; l[pos] = i; str.push_back(s[i]);} r[pos] = i;
	}
	for(int i = 0 ; i < str.size() ; ++i)
		if(qg((1 << str.size()) - 1 - (1 << i))) ans.push_back(str[i]);
	sort(ans.begin() , ans.end()); cout << ans.size(); for(auto t : ans){cout << ' ' << t;} return 0;
}