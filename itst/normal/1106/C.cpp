#include<bits/stdc++.h>
#define int long long
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

const int MAXN = 3e5 + 7;
int num[MAXN] , N;

signed main(){
	N = read();
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		num[i] = read();
		sum += num[i] * num[i];
	}
	sort(num + 1 , num + N + 1);
	for(int i = 1 ; N - i + 1 > i ; ++i)
		sum += 2 * num[i] * num[N - i + 1];
	cout << sum;
	return 0;
}