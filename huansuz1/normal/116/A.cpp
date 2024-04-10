#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
   
   
#define sz 20
#define N 1299721   
#define ll long long
    
using namespace std;
   
int main(){
	int n,a[1234],b[1234],s=0,m=0;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i]>>b[i];         
		s-=a[i];
		s+=b[i];
		if (s>m) m=s;
		}
	cout<<m;   

    return 0;
}