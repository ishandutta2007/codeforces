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

int n,k,z=1;
string s,l,t;

int main() {
     cin>>s>>t;

     for (int i=s.length()-1; i>=0; i--)
     	l+=s[i];
     if (l==t) cout<<"YES"; else cout<<"NO";
     
     return 0;
}