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

const int MAXN = 150 * 150 + 10;
struct node{
	int l , r;
}now[MAXN];
int cnt , ans;

bool operator <(node a , node b){
	return a.l == b.l ? (a.l & 1 ? a.r < b.r : a.r > b.r) : a.l < b.l;
}

inline int abss(int x){
	return x < 0 ? -x : x;
}

inline char getc(){
	char c = getchar();
	while(!isupper(c))
		c = getchar();
	return c;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	int N = read() , M = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			if(getc() == 'W'){
				now[++cnt].l = i;
				now[cnt].r = j;
			}
	now[++cnt].l = 1;
	now[cnt].r = 1;
	sort(now + 1 , now + cnt + 1);
	for(int i = 2 ; i <= cnt ; ++i)
		ans += abss(now[i].l - now[i - 1].l) + abss(now[i].r - now[i - 1].r);
	cout << ans;
	return 0;
}