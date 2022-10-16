
#include <bits/stdc++.h>
#define DMAX 
using namespace std;

int main()
{
	int v[] = {6 , 8, 4, 2}	, n;
	cin >> n;
	if(n==0) cout << 1;
	else cout << v[n%4];
}