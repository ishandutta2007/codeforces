#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

const int _ = 1e4 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , fa[_] , cntEd = 1 , N , M , col[_];
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

bool check(int x){
	bool flg = 0;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(!col[Ed[i].end]){col[Ed[i].end] = 3 - col[x]; flg |= check(Ed[i].end);}
		else flg |= col[Ed[i].end] == col[x];
	return flg;
}

int sum[_] , dep[_] , edid[_] , cur;
int dfs(int x , int pid){
	int num = 0; dep[x] = dep[Ed[pid].end] + 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(i != pid)
			if(!dep[Ed[i].end]){edid[Ed[i].end] = i >> 1; num += dfs(Ed[i].end , i ^ 1); sum[x] += sum[Ed[i].end];}
			else if(dep[Ed[i].end] < dep[x])
				if((dep[x] - dep[Ed[i].end]) & 1){--sum[x]; ++sum[Ed[i].end];}
				else{++sum[x]; --sum[Ed[i].end]; ++num; cur = i >> 1;}
	return num;
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= M ; ++i){
		int p = read() , q = read(); if(p > q) swap(p , q);
		addEd(p , q); addEd(q , p); fa[find(p)] = find(q);
	}
	int id = 0; for(int i = 1 ; i <= N ; ++i) if(!col[i]){col[i] = 1; if(check(i)) if(!id) id = i; else{puts("0"); return 0;}}
	if(!id){printf("%d\n" , M); for(int i = 1 ; i <= M ; ++i) printf("%d " , i);}
	else{
		vector < int > val; int cnt = dfs(id , 0);
		for(int i = 1 ; i <= N ; ++i) if(sum[i] == cnt) val.push_back(edid[i]);
		if(cnt == 1) val.push_back(cur);
		sort(val.begin() , val.end());
		printf("%d\n" , val.size()); for(auto t : val) printf("%d " , t);
	}
	return 0;
}