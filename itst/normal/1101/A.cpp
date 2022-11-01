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

int main(){
	int Q = read();
	while(Q--){
		int l = read() , r = read() , d = read();
		if(l / d == 0 || l / d == 1 && l % d == 0)
			cout << (r / d + 1) * d << endl;
		else
			cout << d << endl;
	}
	return 0;
}