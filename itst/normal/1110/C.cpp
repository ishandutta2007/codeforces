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

int main(){
	for(int Q = read() ; Q ; --Q){
		int a = read();
		for(int i = 24 ; i >= 0 ; --i)
			if((a & 1 << i)){
				if(a != (1 << (i + 1)) - 1)
					cout << (1 << (i + 1)) - 1 << endl;
				else {
					int maxN = 1;
					for(int j = 2 ; j * j <= a ; ++j)
						if(a % j == 0){
							maxN = a / j;
							break;
						}
					cout << maxN << endl;
				}
				break;
			} 
	}
	return 0;
}