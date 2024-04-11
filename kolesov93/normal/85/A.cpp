#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>
using namespace std;

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n;
	cin >> n;
	if (n == 1) {
		cout << "a" << endl;
		cout << "a" << endl;
		cout << "b" << endl;
		cout << "b" << endl;
		return 0;
	}
	
	
	if (n % 2 == 0) {
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "bb";
			else cout << "aa";
		cout << endl;
		
		cout << "c";
		for (int i=0;i+1<n/2;i++) 
			if (i & 1) cout << "ee";
			else cout << "ff";
		cout << "d" << endl;
		
		cout << "c";
		for (int i=0;i+1<n/2;i++) 
			if (i & 1) cout << "gg";
			else cout << "hh";
		cout << "d" << endl;
		
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "aa";
			else cout << "bb";
		cout << endl;
	} else {
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "bb";
			else cout << "aa";
		cout << "c" << endl;
		
		
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "gg";
			else cout << "hh";
		cout << "c" << endl;
		
		cout << "c";
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "bb";
			else cout << "aa";
		cout << endl;
		
		cout << "c";
		for (int i=0;i<n/2;i++) 
			if (i & 1) cout << "gg";
			else cout << "hh";
		cout << endl;
	}
	
	
	
	
	return 0;
}