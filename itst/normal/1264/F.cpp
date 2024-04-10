#include<bits/stdc++.h>
using namespace std;

const int num = 368131125;

int main(){
	int N , A , D; cin >> N >> A >> D;
	cout << 1ull * A * num % 1000000000 * 12 * 1000000000 + 1 << ' ' << 1ull * D * num % 1000000000 * 12 * 1000000000 << endl;
	return 0;
}