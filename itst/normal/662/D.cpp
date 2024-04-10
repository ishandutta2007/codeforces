#include<bits/stdc++.h>
#define P pair < int , int >
using namespace std;

inline pair < int , int > read(){
	int a = 0 , len = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		++len;
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return P(a , len);
}

int main(){
	int T = read().first;
	for(int i = 1 ; i <= T ; ++i){
		P x = read();
		int p = 1988 , times = 1;
		for(int i = 1 ; i <= x.second ; ++i){
			p += times;
			while(x.first / times % 10 != p / times % 10)
				p += times;
			times *= 10;
		}
		printf("%d\n" , p);
	}
	return 0;
}