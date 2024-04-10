#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
#include <string>
using namespace std;
int n;
string s,t="ABCDEFGHIJKLMNOPQRSTUVWXYZ",l="abcdefghijklmnopqrstuvwxyz";
int main(){
cin>>s;
for (int i=0; i<s.length(); i++)
for (int j=0; j<26; j++)
if (s[i]==t[j]) {s[i]=l[j]; break;}

l="bcdfghjklmnpqrstvwxz";
for (int i=0; i<s.length(); i++)
for (int j=0; j<l.length(); j++)
if (s[i]==l[j]) cout<<'.'<<l[j];

return 0;
}