#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;
long long n,a[234567],s, sum, q, p;               
int main(){
cin>>n>>s;
for (int i=0; i<n; i++) { 
	cin>>a[i];           
	sum += a[i];
}
if (n==1) {
	cout<<a[0]-1; 
	exit(0); 
}

for (int i = 0; i < n; i++) {
 	p = max(1ll, s-(sum - a[i]));
 	q = min(a[i], s-n+1);
 	cout << a[i] - (q - p + 1) << " ";
}
return 0;
}