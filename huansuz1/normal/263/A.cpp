#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int x,y;
int a[12][12];

int main() {

	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++) {
			cin>>a[i][j];      
			if (a[i][j]==1) { 
				x=i+1; 
				y=j+1;
			}
		}

	int q = abs(3-x);
	int w = abs(3-y);
	cout<<(q+w);
	return 0;
}