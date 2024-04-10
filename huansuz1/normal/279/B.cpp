#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;


long long n,k,a[234456],s,p=1,y,z,ma;

int main(){
    cin>>n>>k;
    for (int i=1; i<=n; i++){
    	cin>>a[i];          
    	z++;
    	s+=a[i];
    	while(s>k){
    		s-=a[p]; 
    		p++; 
    		z--; 	 
    	}
    	if (z>ma) ma=z;
    }    
    cout<<ma;

    return 0;
}