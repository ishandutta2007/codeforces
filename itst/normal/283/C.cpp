#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int MOD = 1e9 + 7;
int bp[2][100003] , val[303] , nxt[303] , pre[303] , N , Q , T; bool vis[303] , ins[303];
void inc(int &a , int b){a = a + b >= MOD ? a + b - MOD : a + b;}

int findval(int x){
	if(!x) return 0;
	if(ins[x]){puts("0"); exit(0);}
	if(vis[x]) return val[x];
	ins[x] = vis[x] = 1; val[x] += findval(nxt[x]);
	ins[x] = 0; return val[x];
}

int main(){
	scanf("%d %d %d" , &N , &Q , &T); int pos = 0; bp[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i) scanf("%d" , val + i);
	for(int i = 1 ; i <= Q ; ++i){
		int a , b; scanf("%d %d" , &a , &b); pre[nxt[b] = a] = b;
	}
	for(int i = 1 ; i <= N ; ++i){
		findval(i); memset(bp[pos ^= 1] , 0 , sizeof(bp[0]));
		for(int j = 0 ; j + val[i] <= T ; ++j){
			inc(bp[pos][j + val[i]] , bp[pos ^ 1][j]);
			inc(bp[pos][j + val[i]] , bp[pos][j]);
		}
		if(!pre[i])
			for(int j = 0 ; j <= T ; ++j) inc(bp[pos][j] , bp[pos ^ 1][j]);
	}
	printf("%d\n" , bp[pos][T]);
	return 0;
}