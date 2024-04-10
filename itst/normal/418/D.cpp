#include<bits/stdc++.h>
#define MAXN 100010
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

struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int head[MAXN] , dep[MAXN] , maxDep[MAXN] , ST[MAXN][20][2] , bef[MAXN] , root[MAXN] , be[MAXN] , logg[MAXN];
int N , cntEd , maxD , maxDir , cntRoot;
bool isRoot[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void dfsForZJ(int k , int fa , int dep){
	if(dep > maxD){
		maxD = dep;
		maxDir = k;
	}
	bef[k] = fa;
	for(int i = head[k] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa)
			dfsForZJ(Ed[i].end , k , dep + 1);
}

inline void findZJ(int start , int end){
	isRoot[root[++cntRoot] = end] = 1;
	while(end != start)
		isRoot[root[++cntRoot] = end = bef[end]] = 1;
}

void dfsForDep(int k , int fa , int belong){
	be[k] = belong;
	for(int i = head[k] ; i ; i = Ed[i].upEd)
		if(!isRoot[Ed[i].end] && Ed[i].end != fa){
			maxDep[Ed[i].end] = dep[Ed[i].end] = dep[k] + 1; 
			dfsForDep(Ed[i].end , k , belong);
			maxDep[k] = max(maxDep[k] , maxDep[Ed[i].end]);
		}
}

void init(){
	for(int i = 1 ; i <= cntRoot ; i++){
		dfsForDep(root[i] , 0 , i);
		ST[i][0][0] = maxDep[root[i]] - i;
		ST[i][0][1] = maxDep[root[i]] + i;
	}
	for(int i = 1 ; 1 << i <= cntRoot ; i++)
		for(int j = 1 ; j + (1 << i) - 1 <= cntRoot ; j++){
			ST[j][i][0] = max(ST[j][i - 1][0] , ST[j + (1 << i - 1)][i - 1][0]);
			ST[j][i][1] = max(ST[j][i - 1][1] , ST[j + (1 << i - 1)][i - 1][1]);
		}
}

inline int query(int l , int r , int dir){
	if(l > r)
		return -0x3f3f3f3f;
	int t = logg[r - l + 1];
	return max(ST[l][t][dir] , ST[r - (1 << t) + 1][t][dir]);
}

int main(){
	N = read();
	for(int i = 2 ; i <= 100000 ; i++)
		logg[i] = logg[i >> 1] + 1;
	for(int i = 1 ; i < N ; i++){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
	dfsForZJ(1 , 0 , 1);
	maxD = 0; 
	int t = maxDir;
	dfsForZJ(t , 0 , 1);
	findZJ(t , maxDir);
	init();
	int M = read();
	long long lastans = 0;
	while(M--){
		int X = read() , Y = read();
		if(be[X] > be[Y])
			swap(X , Y);
		if(be[X] == be[Y])
			lastans = min(dep[X] , dep[Y]) + max(be[X] - 1 , cntRoot - be[X]);
		else{
			int t = be[X] + be[Y] + dep[Y] - dep[X];
			if(t <= be[X] << 1)
				lastans = dep[Y] + max(be[Y] - 1 , cntRoot - be[Y]);
			else
				if(t >= be[Y] << 1)
					lastans = dep[X] + max(be[X] - 1 , cntRoot - be[X]);
				else{
					t >>= 1;
					lastans = max(max(be[X] - 1 , query(be[X] + 1 , t , 1) - be[X]) + dep[X]
					 , max(query(t + 1 , be[Y] - 1 , 0) + be[Y] , cntRoot - be[Y]) + dep[Y]);
				}
		}
		cout << lastans << endl;
	}
	return 0;
}