#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;
int k,l,m,n,d,z; 

int main(){
	cin>>k>>l>>m>>n>>d;
	for (int i=1; i<=d; i++)
		if (i%k==0 || i%l==0 || i%m==0 || i%n==0) z++;
	cout<<z;
    }