#include<iostream>
#include<cstdio>
#include<bitset>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

bitset < 41 > Edge[41] , cur , choose;
string mod[41] , s;
int N , M , cnt , maxN;

inline int find(){
	for(int i = 1 ; i <= cnt ; ++i)
		if(mod[i] == s)
			return i;
	mod[++cnt] = s;
	return cnt;
}

void dfs(int x){
	if(choose.count() + x <= maxN)
		return;
	if(!x){
		maxN = choose.count();
		return;
	}
	if((Edge[x] & choose) == choose){
		choose.set(x);
		dfs(x - 1);
		choose.reset(x);
	}
	dfs(x - 1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= M ; ++i)
		Edge[i].set();
	for(int i = 1 ; i <= N ; ++i)
		if(read() == 1)
			cur.reset();
		else{
			cin >> s;
			int t = find();
			if(!cur[t]){
				for(int i = 1 ; i <= cnt ; ++i)
					if(cur[i])
						Edge[i][t] = Edge[t][i] = 0;
				cur.set(t);
			}
		}
	dfs(M);
	cout << maxN;
	return 0;
}