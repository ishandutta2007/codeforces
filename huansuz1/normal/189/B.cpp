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

long long n,a,b,s,z,z1;

int main() {
	cin>>a>>b;
	if (a>=2 && b>=2) {
		for (int i=1; i<=a/2; i++) { 
			for (int j=1; j<=b/2; j++) {
				s+=((a-i)-i+1)*((b-j)-j+1);	
			}
		}
				
	}                     
	cout<<s;

	return 0;
}