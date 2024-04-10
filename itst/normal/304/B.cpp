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

int a , b , c , d , e , f;

inline bool calcYear(int x){
	return x % 4 == 0 && (x % 100 != 0 || x % 400 == 0);
}

inline int calcMonth(int x){
	switch(x){
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 28 + calcYear(a);
	default:
		return 31;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
#endif
	scanf("%d:%d:%d %d:%d:%d" , &a , &b , &c , &d , &e , &f);
	int cnt = 0;
	if(a > d || (a == d && (b > e || (b == e && c > f)))){
		swap(a , d);
		swap(b , e);
		swap(c , f);
	}
	while(a != d || b != e || c != f){
		if(c == calcMonth(b)){
			if(b == 12){
				++a;
				b = 1;
			}
			else
				++b;
			c = 1;
		}
		else
			++c;
		++cnt;
	}
	cout << cnt;
	return 0;
}