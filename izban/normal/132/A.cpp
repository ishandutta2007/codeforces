#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,k,p;
string s;
int a[1000],b[1000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	getline(cin,s);
	for (int i=0; i<s.length(); i++) {
		k=s[i];
		p=0;
		for (int j=1; j<8; j++) 
			if ((k>>j)%2) p+=1<<(8-j-1);
		if (k%2) p+=1<<7;
		k=p;
		b[i]=p;
		int prev;
		if (i) prev=b[i-1]; else prev=0;
		int x=(prev-k);
		x=x+(x<0)*256;
		cout << x << endl;
	}
	/*for (int i=0; i<13; i++) {
		cin >> a[i];
		if (i) k=0; else k=b[i-1];
		k=k-a[i]; k=k+(k<0)*256;
		for (int j=1; j<8; j++) 
			if ((k>>j)%2) p+=1<<(8-j-1);
		if (k%2) p+=1<<7;
		b[i]=k;
		k=p;
		cout << char(k);
	}*/
	return 0;
}