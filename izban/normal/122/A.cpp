#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))


bool f(int x){ 
	while (x) {
		if (x%10==4 || x%10==7)  x/=10; 
		else return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);       
        freopen("output.txt", "w", stdout);
#endif
		int n; bool b=false;
		cin >> n;
		for (int i=1; i<=n; i++) {
			if (f(i) && !(n%i)) b=true;
		}
		b? cout << "YES" : cout << "NO";
        return 0;
}