#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

string a,b,x,y;
int k=0;

int main(){
    cin>>a>>b;
    k=a.length();
    for (int i=0; i<a.length(); i++)
        if (a[i]!='0') { k=i; break; }  
    for (int i=k; i<a.length(); i++)
        x+=a[i];
    k=b.length();
    for (int i=0; i<b.length(); i++)
        if (b[i]!='0') { k=i; break; }  
    for (int i=k; i<b.length(); i++)
        y+=b[i];
    if (x.length()>y.length()) {cout<<">"; return 0;}
    if (x.length()<y.length()) {cout<<"<"; return 0;}
    if (x==y) {cout<<"="; return 0;}
    for (int i=0; i<x.length(); i++)
        if (x[i]>y[i]) { cout<<">"; return 0; } else
        if (x[i]<y[i]) { cout<<"<"; return 0; }




    return 0;             
}