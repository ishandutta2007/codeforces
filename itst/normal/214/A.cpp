#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n , m , cou = 0;
	cin >> n >> m;
	for(int i = 0 ; i * i <= n && i <= m ; i++)
		if((n - i * i) * (n - i * i) == m - i)	cou++;
	cout << cou;
    return 0;
}