#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , l[3];
	cin >> n >> l[0] >> l[1] >> l[2];
	if(min(min(l[0] , l[1]) , l[2]) == l[2] && n - 1)   cout << min(l[0] , l[1]) + (n - 2) * l[2];
	else    cout << (n - 1) * min(l[0] , l[1]);
	return 0;
}