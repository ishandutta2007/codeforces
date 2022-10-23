#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define PER(i, a, b) for(int i = a; i >= b; i--)
#define LL long long
inline int read(){
    int x = 0, flag = 1;char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') flag = -1;
        ch = getchar();
    }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}

double calc(double b, double h) {
	double dlen = sqrt(b * b + h * h);
	return b * h / dlen;
}
int main() {
	double h, w, r;
	cin >> r;
	for(w = 1; w <= 10; ++ w)
		for(h = 1; h <= 10; ++h)
			if(abs(r - calc(w / 2, h)) <= 1e-6) {
				cout << w << " " << h << endl;
				return 0;
			}
	
    return 0;
}