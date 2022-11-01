#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

#define PII pair < int , int >
#define st first
#define nd second
vector < int > A , B;
vector < PII > seat;
priority_queue < int > q;

bool cmp(int a , int b){return a > b;}

int abss(int x){return x < 0 ? -x : x;}

int dist(int x1 , int y1 , int x2 , int y2){
	return abss(x2 - x1) + abss(y2 - y1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	int N = read() , M = read() , K = read();
	for(int i = 1 ; i <= K ; ++i)
		A.push_back(read());
	sort(A.begin() , A.end());
	read();
	for(int i = 1 ; i <= N * M - K ; ++i)
		B.push_back(read());
	sort(B.begin() , B.end() , cmp);
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j)
			seat.push_back(PII(dist(i , j , 0 , 0) , dist(i , j , 0 , M + 1)));
	sort(seat.begin() , seat.end());
	int pos = 0;
	for(auto t : A){
		while(pos < seat.size() && seat[pos].st <= t)
			q.push(seat[pos++].nd);
		if(q.empty()){
			puts("NO");
			return 0;
		}
		q.pop();
	}
	while(pos < seat.size())
		q.push(seat[pos++].nd);
	for(auto t : B)
		if(q.top() > t){
			puts("NO");
			return 0;
		}
		else q.pop();
	puts("YES");
	return 0;
}