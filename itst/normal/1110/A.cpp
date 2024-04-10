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

int arr[100010] , n , b , k;

int main(){
	b = read();
	k = read();
	for(int i = k - 1 ; i >= 0 ; --i)
		arr[i] = read();
	bool cnt = 0;
	int cur = 1;
	for(int i = 0 ; i < k ; ++i){
		cnt ^= ((arr[i] * cur) & 1);
		cur = (cur * b) & 1;
	}
	cout << (cnt ? "odd" : "even");
	return 0;
}