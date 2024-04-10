
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n,a[123][123],z,s;

int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];
	for(int i=0; i<n; i++) 
		for (int j=0; j<n; j++) {
			s=0;
			for (int o=0; o<n; o++)
				s+=a[i][o]-a[o][j];
			if (s<0) z++;
					
	}
	cout<<z;
		                                                  

	return 0;
}