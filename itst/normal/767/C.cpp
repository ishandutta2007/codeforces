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

const int MAXN = 1000010;
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , num[MAXN] , sum[MAXN] , all , N , cntEd , ans , root;
bool have[MAXN] , f;

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfs(int x , int pre){
	sum[x] += num[x];
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != pre){
			dfs(Ed[i].end , x);
			sum[x] += sum[Ed[i].end];
			have[x] |= have[Ed[i].end];
		}
	if(x != root && ((sum[x] == all / 3 && !have[x]) || (sum[x] == all * 2 / 3 && have[x])))
		if(!f){
			f = 1;
			ans = x;
			have[x] = 1;
		}
		else{
			cout << ans << ' ' << x << endl;
			exit(0);
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("767C.in" , "r" , stdin);
	//freopen("767C.out" , "w" , stdout);
#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int a = read() , b = read();
		if(a)
			addEd(a , i);
		else
			root = i;
		num[i] = b;
		all += b;
	}
	if(all % 3){
		puts("-1");
		return 0;
	}
	dfs(root , 0);
	puts("-1");
	return 0;
}