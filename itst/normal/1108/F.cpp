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

const int MAXN = 2e5 + 3;
struct Edge{
	int s , t , w;
	const operator <(const Edge a)const{
		return w < a.w;
	}
}Ed[MAXN];
int fa[MAXN] , pre[MAXN] , N , M;

int find(int* fa , int x){
	return fa[x] == x ? x : (fa[x] = find(fa , fa[x]));
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	M = read();
	for(int i = 1 ; i <= N ; ++i)
		fa[i] = pre[i] = i;
	for(int i = 1 ; i <= M ; ++i){
		Ed[i].s = read(); 
		Ed[i].t = read();
		Ed[i].w = read();
	}
	sort(Ed + 1 , Ed + M + 1);
	int cnt = 0;
	for(int i = 1 , pi = 1 ; i <= M ; i = pi){
		while(pi <= M && Ed[i].w == Ed[pi].w)
			++pi;
		for(int j = i ; j < pi ; ++j)
			if(find(fa , Ed[j].s) != find(fa , Ed[j].t))
				fa[find(fa , Ed[j].s)] = find(fa , Ed[j].t);
			else
				if(find(pre , Ed[j].s) != find(pre , Ed[j].t))
					++cnt;
		for(int j = i ; j < pi ; ++j)
			if(find(pre , Ed[j].s) != find(pre , Ed[j].t))
				pre[find(pre , Ed[j].s)] = find(pre , Ed[j].t);
	}
	cout << cnt;
	return 0;
}