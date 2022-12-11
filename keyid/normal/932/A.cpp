#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

int main()
{
	string a;
	cin>> a;
	cout << a;
	for (int i=a.size()-1;i>=0;i--)
		cout << a[i];
	return 0;
}