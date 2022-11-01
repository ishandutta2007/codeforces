#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 100010;
char c[25][2] , s1[MAXN] , s2[MAXN];
int fa[27];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("939D.in" , "r" , stdin);
	//freopen("939D.out" , "w" , stdout);
#endif
	int N = read();
	int cnt = 0;
	scanf("%s%s" , s1 + 1 , s2 + 1);
	for(int i = 1 ; i <= 26 ; ++i)
		fa[i] = i;
	for(int i = 1 ; i <= N ; ++i)
		if(find(s1[i] - 'a') != find(s2[i] - 'a')){
			c[++cnt][0] = find(s1[i] - 'a') + 'a';
			c[cnt][1] = find(s2[i] - 'a') + 'a';
			fa[find(s1[i] - 'a')] = find(s2[i] - 'a');
		}
	cout << cnt << endl;
	for(int i = 1 ; i <= cnt ; ++i)
		cout << c[i][0] << ' ' << c[i][1] << endl;
	return 0;
}