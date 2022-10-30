#include<bits/stdc++.h>
#define ld long double
#define eps 1e-10
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

const int MAXN = 300010;
struct point{
	int a , b , ind;
}now[MAXN];
int nxt[MAXN] , pre[MAXN] , S[MAXN] , tl;
bool can[MAXN];

bool cmp(point a , point b){
	if(a.a == b.a)
		return a.b > b.b;
	return a.a > b.a;
}

ld calcK(point a , point b){
	return (ld)a.a * b.a * (b.b - a.b) / a.b / b.b / (b.a - a.a);
}

int main(){
	int N = read();
	for(int i = 1 ; i <= N ; i++){
		now[i].a = read();
		now[i].b = read();
		now[i].ind = i;
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	sort(now + 1 , now + N + 1 , cmp);
	int maxB = now[1].b;
	for(int i = 2 ; i <= N ; i++)
		if(now[i].b <= maxB){
			nxt[pre[i]] = nxt[i];
			pre[nxt[i]] = pre[i];
		}
		else
			maxB = now[i].b;
	S[0] = 1;
	tl = 1;
	for(int i = nxt[1] ; i <= N ; i = nxt[i]){
		while(tl != 1 && calcK(now[i] , now[S[tl - 1]]) < calcK(now[S[tl - 2]] , now[S[tl - 1]]))
			tl--;
		S[tl++] = i;
	}
	for(int i = 0 ; i < tl ; i++){
		can[now[S[i]].ind] = 1;
		for(int j = S[i] + 1 ; j <= N && now[S[i]].a == now[j].a && now[S[i]].b == now[j].b ; j++)
			can[now[j].ind] = 1;
	}
	for(int i = 1 ; i <= N ; i++)
		if(can[i])
			printf("%d " , i);
	return 0;
}