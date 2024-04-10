#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>

#define f first
#define s second
#define mp make_pair
#define ll long long

using namespace std;

int x , y , z , a , b , c;	

int main() {
	cin >> x >> y >> z;
	for (int i=1; i<=x; i++) {
		if (x%i==0) {
			a=x/i; 
			b=i;
			if (y%b==0) { c=y/b;
			if (z == c*a) {cout<<a*4+b*4+c*4; return 0;}
			}
			swap(a,b);
			if (y%b==0) { c=y/b;
			if (z == c*a) {cout<<a*4+b*4+c*4; return 0;}
			}
		}
	}




}