#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
int n,m,a[1234],b[1234];
int main(){
	cin>>n;
     for (int i=1; i<=n; i++){
     cin>>a[i]>>b[i];               
     if (b[i]-a[i]>=2) m++;
     }
	cout<<m;
	}