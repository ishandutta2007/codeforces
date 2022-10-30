#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair                                                        
#define ll long long

using namespace std;

string s,l;

int main(){
    cin>>s;
    if (s.length()<=2){cout<<s; return 0;}
    s+=' ';
    int k=0;
    
    for (int i=0; i<s.length(); i++)
        if (s[i]!=l[l.length()-1] || s[i]!=l[l.length()-2]) l+=s[i];
    for (int i=0; i<l.length()-3; i++)      
        if (l[i]==l[i+1] && l[i+2]==l[i+3]) l[i+2]=' ';
    for (int i=0; i<l.length(); i++)
        if (l[i]!=' ') cout<<l[i];


    return 0;
}