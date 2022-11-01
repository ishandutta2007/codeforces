#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b;
	cin >> a >> b;
	if(min(a , b) % 2)	cout << "Akshat";
	else	cout << "Malvika";
	return 0;
}