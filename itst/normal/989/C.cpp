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

char s[52][52];

int main(){
#ifndef ONLINE_JUDGE
	freopen("989C.in" , "r" , stdin);
	//freopen("989C.out" , "w" , stdout);
#endif
	int a = read() - 1 , b = read() - 1 , c = read() - 1 , d = read() - 1;
	cout << 50 << ' ' << 50 << endl;
	for(int i = 1 ; i <= 25 ; ++i)
		for(int j = 1 ; j <= 25 ; ++j)
			s[i][j] = 'A';
	for(int i = 1 ; i <= 25 ; ++i)
		for(int j = 26 ; j <= 50 ; ++j)
			s[i][j] = 'B';
	for(int i = 26 ; i <= 50 ; ++i)
		for(int j = 1 ; j <= 25 ; ++j)
			s[i][j] = 'C';
	for(int i = 26 ; i <= 50 ; ++i)
		for(int j = 26 ; j <= 50 ; ++j)
			s[i][j] = 'D';
	for(int i = 1 ; i <= 25 && a ; i += 2)
		for(int j = 27 ; j <= 50 && a ; j += 2){
			s[i][j] = 'A';
			--a;
		}
	for(int i = 26 ; i <= 50 && b ; i += 2)
		for(int j = 1 ; j <= 25 && b ; j += 2){
			s[i][j] = 'B';
			--b;
		}
	for(int i = 26 ; i <= 50 && c ; i += 2)
		for(int j = 27 ; j <= 50 && c ; j += 2){
			s[i][j] = 'C';
			--c;
		}
	for(int i = 1 ; i <= 25 && d ; i += 2)
		for(int j = 1 ; j <= 25 && d ; j += 2){
			s[i][j] = 'D';
			--d;
		}
	for(int i = 1 ; i <= 50 ; ++i){
		for(int j = 1 ; j <= 50 ; ++j)
			cout << s[i][j];
		cout << endl;
	}
	return 0;
}