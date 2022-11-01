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

inline char getc(){
	char c =getchar();
	while(c == '\n' || c == '\r' || c == ' ')
		c = getchar();
	return c;
}
char mMap[510][510];
int N , M;

int main(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			mMap[i][j] = getc();
	int cnt = 0;
	for(int i = 2 ; i < N ; ++i)
		for(int j = 2 ; j < N ; ++j)
			if(mMap[i][j] == 'X' && mMap[i - 1][j - 1] == 'X' && mMap[i - 1][j + 1] == 'X' && mMap[i + 1][j - 1] == 'X' && mMap[i + 1][j + 1] == 'X')
				++cnt;
	cout << cnt;
	return 0;
}