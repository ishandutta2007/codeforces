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

int n,m;
int main() {
    cin>>n>>m;
    if (n==1) { cout<<1; return 0; }
    if (m<=(n/2) && m%2==0) { cout<<m+1; return 0; } 
    if (m<(n/2)+(m%2)) { cout<<m+1; return 0; } else { cout<<m-1; return 0; }




    return 0;
}