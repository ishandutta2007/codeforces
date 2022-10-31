#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define mod 1000000007
#define pii pair <int , int>
#define f first
#define s second
#define pb push_back
#define ll long long
    int n,m,a[1234],ma=10000,b[1234],z;
    int main(){
    	cin>>n;
    	for (int i=0; i<n; i++)
    		cin>>a[i];
    	for (int i=1; i<n-1; i++) {
    		if ((a[i]-a[i-1])+(a[i+1]-a[i])<ma) {ma=(a[i]-a[i-1])+(a[i+1]-a[i]);	m=i;}
    		
    	}
    	for (int i=0; i<n; i++)    	
    		if (i!=m) b[z++]=a[i]; 
    		ma=0;
    	for (int i=1; i<z; i++)
    		if (b[i]-b[i-1]>ma)  ma=b[i]-b[i-1];
    	cout<<ma;   


    return 0;
}