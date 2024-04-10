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

int n;

int main() {
    cin>>n;
    if (n<=2) cout<<-1; else {
    	for (int i=n; i>=1; i--)
    		cout<<i<<" ";
    
    }
    
    
    
    return 0;
}