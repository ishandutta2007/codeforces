#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n, k;
	cin >> n >> k;
	cout << max((k + 1) / 2 - max(1LL, k - n), 0LL) << "\n";
	return 0;
}

/*
a+b=k
1<=a<k-a<=n
1<=a
2a<k
k-n<=a
max(1,k-n)<=a<k/2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////