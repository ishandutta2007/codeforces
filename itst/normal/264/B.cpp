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

int maxLen[100007] , N;

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("in" , "r" , stdin);
	//freopen("out" , "w" , stdout);
	#endif
	N = read();
	for(int i = 1 ; i <= N ; ++i){
		int a = read() , maxN = 0;
		vector < int > zys;
		for(int j = 2 ; j * j <= a ; ++j)
			if(a % j == 0){
				zys.push_back(j);
				maxN = max(maxN , maxLen[j]);
				while(a % j == 0)
					a /= j;
			}
		if(a - 1){
			zys.push_back(a);
			maxN = max(maxN , maxLen[a]);
		}
		++maxN;
		for(int j = 0 ; j < zys.size() ; ++j)
			maxLen[zys[j]] = maxN;
	}
	int maxN = 1;
	for(int i = 1 ; i <= 100000 ; ++i)
		maxN = max(maxN , maxLen[i]);
	cout << maxN;
	return 0;
}