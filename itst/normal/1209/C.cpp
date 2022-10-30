#include<bits/stdc++.h>
using namespace std;

int T; bool vis[200003];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		int L; string s; cin >> L >> s; bool getans = 0;
		for(int i = 0 ; i < 9 && !getans ; ++i){
			memset(vis , 0 , sizeof(bool) * (s.size()));
			int mx = 0 , pre = -1; bool flg = 1;
			for(int j = 0 ; j < s.size() ; ++j)
				if(s[j] - '0' <= i){
					if(mx > s[j] - '0'){flg = 0; break;}
					pre = j; mx = max(mx , s[j] - '0'); vis[j] = 1;
				}
			if(!flg) continue;
			for(int j = pre + 1 ; j < s.size() ; ++j)
				if(s[j] - '0' == i + 1) vis[j] = 1;
			mx = 0;
			for(int j = 0 ; j < s.size() ; ++j)
				if(!vis[j]){
					if(mx > s[j] - '0'){flg = 0; break;}
					mx = s[j] - '0';
				}
			if(flg){
				getans = 1;
				for(int i = 0 ; i < s.size() ; ++i) putchar(vis[i] ? '1' : '2');
			}
		}
		if(!getans) putchar('-');
		putchar('\n');
	}
	return 0;
}