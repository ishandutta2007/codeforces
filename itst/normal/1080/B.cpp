#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int sum(int x){
	return x % 2 == 0 ? x >> 1 : (x >> 1) - x;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("B.in" , "r" , stdin);
	//freopen("B.out" , "w" , stdout);
#endif
	for(int q = read() ; q ; --q){
		int l = read() , r = read();
		cout << sum(r) - sum(l - 1) << endl;
	}
	return 0;
}