#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int seed = 131 , MAXN = 1e5 + 10 , mzz = 998244353 , gzy = 1e9 + 9;
map < string , int > Hash;
int N , M , K , cnt , fa[MAXN << 1];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline string has(string s){
	return s;
}

int main(){
	string s1 , s2;
	cin >> N >> M >> K;
	for(int i = 1 ; i <= N << 1 ; ++i)
		fa[i] = i;
	for(int i = 1 ; i <= N ; ++i){
		cin >> s1;
		Hash[has(s1)] = ++cnt;
	}
	for(int i = 1 ; i <= M ; ++i){
		int a = read();
		cin >> s1 >> s2;
		int b = Hash[has(s1)] , c = Hash[has(s2)];
		if(a == 1)
			if(find(b) == find(c + N))
				puts("NO");
			else{
				fa[find(b)] = find(c);
				fa[find(b + N)] = find(c + N);
				puts("YES");
			}
		else
			if(find(b) == find(c))
				puts("NO");
			else{
				fa[find(b)] = find(c + N);
				fa[find(b + N)] = find(c);
				puts("YES");
			}
	}
	while(K--){
		cin >> s1 >> s2;
		int b = Hash[has(s1)] , c = Hash[has(s2)];
		cout << (find(b) == find(c) ? 1 : (find(b) == find(c + N) ? 2 : 3)) << '\n';
	}
	return 0;
}