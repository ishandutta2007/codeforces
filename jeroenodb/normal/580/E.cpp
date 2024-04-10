#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5+1;
char serial[mxN];
int main() {
	int n,m,k;
	cin >> n >> m >> k;
	cin >> serial;
	for(int i=0;i<m+k;++i) {
		int tmp, l, r, d;
		cin >> tmp >> l >> r >> d;
		--l;--r;
		if(tmp==1) {
			memset (serial+l,(char)(d+'0'),(r-l+1)*sizeof(char));
			//cout << serial << endl;
		} else {
			cout << (memcmp(serial+l,serial+(l+d),r-l+1-d)==0?"YES":"NO")<<endl;
		}
	}

    
}