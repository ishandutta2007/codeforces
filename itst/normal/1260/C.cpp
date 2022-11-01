#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

int T , p1 , p2 , K;

int gcd(int p , int q){int r = p % q; while(r){p = q; q = r; r = p % q;} return q;}
int main(){
	for(T = read() ; T ; --T){
		p1 = read(); p2 = read(); K = read();
		if(K == 1) puts("REBEL");
		else if(p1 == p2) puts("OBEY");
		else{
			if(p1 > p2) swap(p1 , p2);
			int t = gcd(p1 , p2);
			puts((p2 - t - 1) / p1 + 1 < K ? "OBEY" : "REBEL");
		}
	}
	return 0;
}