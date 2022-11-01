#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

string s , a , b;
int to[27] , k , T;
bool vis[27];

bool up(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > a[dir] - 'a')
			return 1;
		if(t < a[dir] - 'a')
			return 0;
		return up(dir + 1);
	}
	for(int i = a[dir] - 'a' + 1 ; i < k ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[a[dir] - 'a']){
		vis[a[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = a[dir] - 'a';
		if(up(dir + 1))
			return 1;
		to[s[dir] - 'a'] = -1;
		vis[a[dir] - 'a'] = 0;
	}
	return 0;
}

bool down(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > b[dir] - 'a')
			return 0;
		if(t < b[dir] - 'a')
			return 1;
		return down(dir + 1);
	}
	for(int i = 0 ; i < b[dir] - 'a' ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[b[dir] - 'a']){
		vis[b[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = b[dir] - 'a';
		if(down(dir + 1))
			return 1;
		to[s[dir] - 'a'] = -1;
		vis[b[dir] - 'a'] = 0;
	}
	return 0;
}

bool dfs(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > a[dir] - 'a' && t < b[dir] - 'a')
			return 1;
		if(t < a[dir] - 'a' || t > b[dir] - 'a')
			return 0;
		if(t == a[dir] - 'a' && t == b[dir] - 'a')
			return dfs(dir + 1);
		if(t == a[dir] - 'a')
			return up(dir + 1);
		if(t == b[dir] - 'a')
			return down(dir + 1);
	}
	for(int i = a[dir] - 'a' + 1 ; i < b[dir] - 'a' ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[a[dir] - 'a']){
		vis[a[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = a[dir] - 'a';
		if(a[dir] - 'a' == b[dir] - 'a')
			return dfs(dir + 1);
		if(up(dir + 1))
			return 1;
		vis[a[dir] - 'a'] = 0;
		to[s[dir] - 'a'] = 0;
	}
	if(!vis[b[dir] - 'a']){
		vis[b[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = b[dir] - 'a';
		if(down(dir + 1))
			return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> k >> s >> a >> b;
		memset(to , -1 , sizeof(to));
		memset(vis , 0 , sizeof(vis));
		if(dfs(0)){
			cout << "YES" << '\n';
			for(int i = 0 ; i < k ; ++i)
				if(to[i] == -1){
					for(int j = 0 ; j < k ; ++j)
						if(!vis[j]){
							vis[j] = 1;
							cout << (char)('a' + j);
							break;
						}
				}
				else
					cout << (char)('a' + to[i]);
			cout << '\n';
		}
		else
			cout << "NO" << '\n';
	}
	return 0;
}