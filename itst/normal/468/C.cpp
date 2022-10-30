#include<bits/stdc++.h>
using namespace std;

#define int long long
main(){
	int A; cin >> A; int delt = A - ((long long)1e18) % A * 9 % A * 9 % A;
	cout << delt << ' ' << delt + (long long)1e18 - 1;
	return 0;
}