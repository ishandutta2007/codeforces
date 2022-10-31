#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;


long long n,s=1,q,z,p;

int main() {
    cin>>n;
    if (n%5!=0) p=1;
    cout<<(n/5)+p;
    return 0;             
}