#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 21; n <= 50; n++){
		cout <<( ((min(n, 25) + n) % (2 + n % 3)) > 0) << endl;
	}
}