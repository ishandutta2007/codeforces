#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n, s, p, m;
int main(){
	cin >> n >> m;
	if (n==2 && m==3) { cout<<"YES"; return 0; }
	if (n==2 && m!=3) { cout<<"NO"; return 0; }


	for (int i=2; i<=sqrt(n); i++)
		if (n%i==0) {p=1; break;}
	
	for (int i=2; i<=sqrt(m); i++)
		if (m%i==0) {p=1; break;}

	if (p==0) {
		for (int i=n+1; i<=m; i++)    {
			p=0;
			for (int j=2; j<=sqrt(i); j++)
				if (i%j==0) {p=1; break;}
			if (p==0) {
			
			if (i==m)cout<<"YES";else cout<<"NO"; return 0;}
	    }
	}
	cout<<"NO";

	return 0;

}