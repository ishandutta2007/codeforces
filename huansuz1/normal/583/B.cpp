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

long long n,z,a[1234567],b[123456],x,y[1234567],ans;

int main() {
    cin>>n;          
    for (int i=0; i<n; i++){
        cin>>a[i];      
    }
    while(z!=n) {
        if (x%2==0){
            for (int i=0; i<n; i++)
                if (a[i]<=z && a[i]!=-1) {z++; a[i]=-1;}
        } else {
            for (int i=n-1; i>=0; i--)
                if (a[i]<=z && a[i]!=-1) {z++; a[i]=-1;}
        }
        x++;
    }
    cout<<x-1;
    
    
    return 0;
}