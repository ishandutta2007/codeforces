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

int N , M , K , num[100010];
priority_queue < int > q;

int main(){
	N = read();
	M = read();
	K = read();
	int sum = 0;
	for(int i = 1 ; i <= N ; ++i){
		num[i] = read();
		if(i - 1)
			q.push(num[i] - num[i - 1] - 1);
	}
	sum = num[N] - num[1] + 1;
	while(--K){
		sum -= q.top();
		q.pop();
	}
	cout << sum;
	return 0;
}