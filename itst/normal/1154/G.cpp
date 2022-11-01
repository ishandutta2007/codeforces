#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int _ = 1e7 + 3 , __ = 1e6 + 3;
int prm[_] , Min[_] , cnt , N , val[__] , ind[__] , minVal[_][2];
bool nprm[_];

void init(){
	for(int i = 2 ; i <= 1e7 ; ++i){
		if(!nprm[i]){
			prm[++cnt] = i;
			Min[i] = cnt;
		}
		for(int j = 1 ; prm[j] * i <= 1e7 ; ++j){
			nprm[prm[j] * i] = 1;
			Min[prm[j] * i] = j;
			if(i % prm[j] == 0) break;
		}
	}
}

#define PII pair < int , int >
#define st first
#define nd second
vector < PII > num;

void dfs(int x , int times , int ind){
	if(x == num.size()){
		if(val[minVal[times][0]] > val[ind]){
			minVal[times][1] = minVal[times][0];
			minVal[times][0] = ind;
		}
		else if(val[minVal[times][1]] > val[ind]) minVal[times][1] = ind;
		return;
	}
	for(int i = 0 ; i <= num[x].nd ; ++i){
		dfs(x + 1 , times , ind);
		times *= prm[num[x].st];
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	init();
	N = read();
	val[0] = 0x3f3f3f3f;
	for(int i = 1 ; i <= N ; ++i){
		val[i] = read();
		ind[i] = i;
	}
	for(int i = 1 ; i <= N ; ++i){
		int p = ind[i] , a = val[p];
		num.clear();
		while(a != 1){
			int t = Min[a];
			a /= prm[t];
			if(!num.empty() && num[(int)num.size() - 1].st == t)
				++num[(int)num.size() - 1].nd;
			else
				num.push_back(PII(t , 1));
		}
		dfs(0 , 1 , p);
	}
	long long minX = 0 , minY = 0 , Min = 1e18;
	for(int i = 1 ; i <= 1e7 ; ++i)
		if(minVal[i][1]){
			int p = minVal[i][0] , q = minVal[i][1];
			if(Min > 1ll * val[p] * val[q] / i)
				Min = 1ll * val[minX = p] * val[minY = q] / i;
		}
	if(minX > minY) swap(minX , minY);
	cout << minX << ' ' << minY << endl;
	return 0;
}