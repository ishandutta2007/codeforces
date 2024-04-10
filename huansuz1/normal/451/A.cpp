#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int n,m;

int main() {
     cin>>n>>m;
     if (n>m) n=m;
     if (n % 2==0) cout<<"Malvika"; else cout<<"Akshat";
     
     return 0;
}