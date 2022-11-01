#include<bits/stdc++.h>
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

const int MAXN = 1e5 + 7;
int c[MAXN] , t[MAXN] , N; 

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		c[i] = read();
	for(int i = 1 ; i <= N ; ++i)
		t[i] = read();
	if(c[1] != t[1]){
		puts("No");
		return 0;
	}
	for(int i = 1 ; i < N ; ++i){
		c[i] = c[i + 1] - c[i];
		t[i] = t[i + 1] - t[i];
	}
	sort(c + 1 , c + N);
	sort(t + 1 , t + N);
	for(int i = 1 ; i < N ; ++i)
		if(c[i] != t[i]){
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}