#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
using namespace std;

int main() {
	int n,ar[123],a = 0,b = 0,k = 0;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>ar[i];
	}
	for (int i = n-1 ; i >= 0; i--)
		if (a == 0 || a <= b) a += ar[i]; else b += ar[i];
	
	cout<<min(a,b)<<" "<<max(a,b);
	
	// your code goes here
	return 0;
}