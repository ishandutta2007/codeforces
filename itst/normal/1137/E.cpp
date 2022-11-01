#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 3e5 + 7;
#define ld long double
#define PII pair < int , int >
#define st first
#define nd second
PII st[MAXN];
int K , B , top , all;
ld getK(PII a , PII b){return (b.nd - a.nd) * 1.0 / (a.st - b.st);}
int calc(PII nd){return (nd.st - 1) * K + nd.nd + B;}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	all = read(); st[top = 1] = PII(1 , 0);
	for(int M = read() ; M ; --M){
		int tp = read();
		if(tp == 1){st[top = 1] = PII(1 , 0); B = K = 0; all += read();}
		else
			if(tp == 2){
				PII now = PII(all + 1 , -calc(PII(all + 1 , 0)));
				while(top > 1 && getK(now , st[top]) >= getK(st[top] , st[top - 1]))
					--top;
				st[++top] = now;
				all += read();
			}
			else{B += read(); K += read();}
		while(top > 1 && calc(st[top]) >= calc(st[top - 1])) --top;
		cout << st[top].st << ' ' << calc(st[top]) << endl;
	}
	return 0;
}