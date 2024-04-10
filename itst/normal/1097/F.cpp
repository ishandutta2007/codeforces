#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c) && c != EOF)
		c = getchar();
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

bitset < 7010 > from[7010] , to[7010] , mset[100010];
int N , Q;
bool vis[7010];

int main(){
	N = read();
	Q = read();
	for(int i = 2 ; i * i <= 7000 ; ++i)
		for(int j = 1 ; j * i * i <= 7000 ; ++j)
			vis[i * i * j] = 1;
	for(int i = 1 ; i <= 7000 ; ++i){
		for(int j = 1 ; j * i <= 7000 ; ++j){
			from[i * j].set(i);
			if(!vis[j])
				to[i].set(i * j);
		}
	}
	int a , b , c;
	for(int i = 1 ; i <= Q ; ++i)
		switch(read()){
		case 1:
			a = read() , b = read();
			mset[a] = from[b];
			break;
		case 2:
			a = read() , b = read() , c = read();
			mset[a] = mset[b] ^ mset[c];
			break;
		case 3:
			a = read() , b = read() , c = read();
			mset[a] = mset[b] & mset[c];
			break;
		case 4:
			a = read() , b = read();
			printf("%d" , (mset[a] & to[b]).count() & 1);
		}
	return 0;
}