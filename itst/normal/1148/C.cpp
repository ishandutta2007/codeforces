#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
//This code is written by Itst
using namespace std;

int read(){
	int a = 0; bool f = 0;
	char c = getchar();
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 3e5 + 3;
int N , P[_] , to[_];
#define PII pair < int , int >
vector < PII > step;

void Swap(int a , int b){
	step.push_back(PII(a , b));
	to[P[a]] = b; to[P[b]] = a;
	swap(P[a] , P[b]);
}

void search(int x){
	if(to[x] == x) return;
	if(x / (N / 2 + 1) == to[x] / (N / 2 + 1)){
		int id = to[x] >= N / 2 + 1 ? 1 : N;
		Swap(id , to[x]); Swap(id , x);
	}
	else{
		if(abs(x - to[x]) + 0.1 >= N / 2)
			Swap(x , to[x]);
		else{
			int id = to[x] >= N / 2 + 1 ? 1 : N;
			Swap(to[x] , id); Swap(id , N + 1 - id); Swap(x , N + 1 - id);
		}
	}
}

signed main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		to[P[i] = read()] = i;
	for(int i = 0 ; i < N / 2 ; ++i){
		search(N / 2 - i); search(N / 2 + 1 + i);
	}
	cout << step.size() << endl;
	for(auto t : step) cout << t.first << ' ' << t.second << endl;
	return 0;
}