#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,m,s;
int main(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
	s++;
	if (s==m) { s=0; n++; }
	}
	
	cout<<n;
}