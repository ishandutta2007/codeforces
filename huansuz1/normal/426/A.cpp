#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n, a[2009], b[3][2009] ,c[2009], z , s;
int main(){
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	sort(a,a+n);
	for (int i=0; i<n-1; i++)
		s-=a[i];
	if (s>=0) cout<<"YES"; else cout<<"NO";
	return 0;

}