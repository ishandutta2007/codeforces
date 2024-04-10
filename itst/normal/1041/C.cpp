#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return a;
}

struct times{
	int num , ind;
}now[MAXN];

int fa[MAXN] , be[MAXN];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

bool cmp(times a , times b){
	return a.num < b.num;
}

int main()
{
	int N = read() , M = read() , D = read() , ans = 0 , dir = 0;
	for(int i = 1 ; i <= N ; i++){
		now[i].num = read();
		fa[i] = now[i].ind = i;
	}
	sort(now + 1 , now + N + 1 , cmp);
	for(int i = 1 ; i <= N ; i++){
		while(now[i].num - now[dir + 1].num > D)
			dir++;
		int t = find(dir);
		if(!t)
			be[now[i].ind] = ++ans;
		else{
			be[now[i].ind] = be[now[t].ind];
			fa[t] = t - 1;
		}
	}
	cout << ans << endl;
	for(int i = 1 ; i <= N ; i++)
		cout << be[i] << ' ';
 	return 0;
}