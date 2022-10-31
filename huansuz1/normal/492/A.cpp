#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

using namespace std;
int n,s,z,m;

int main() {
	cin>>n;
	for (int i=1; i<=10000; i++) {
		for (int j=1; j<=i; j++)  
			s+=j;
		if (s>n) {cout<<i-1;break;}
	}
			

	return 0;
}