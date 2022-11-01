#include<bits/stdc++.h>
//This code is written by Itst
#define lch (x << 1)
#define rch (x << 1 | 1)
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

const int MAXN = 5e5 + 10;
int Max1 , Max2;

inline char getc(){
	char c = getchar();
	while(c != '+' && c != '?')
		c = getchar();
	return c;
}

int main(){
	int N = read();
	while(N--)
		if(getc() == '+'){
			int a = read() , b = read();
			Max1 = max(Max1 , max(a , b));
			Max2 = max(Max2 , min(a , b));
		}
		else{
			int h = read() , w = read();
			puts(max(h , w) >= Max1 && min(h , w) >= Max2 ? "YES" : "NO");
		}
	return 0;
}