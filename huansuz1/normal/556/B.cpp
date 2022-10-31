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

map<int,int> st,ss;
map<int,int> :: iterator it;
int n, x,y,xx,yy,c,b,ans,a[12323];
char ch;

int main() {
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    for (int j=0; j<1000; j++) {
        for (int i=0; i<n; i++) {
            if (i>=a[i] && (n-i+a[i]-1>=i-a[i])) a[i]++; else 
            if (i<a[i] && (n-a[i]-1+i<a[i]-i)) a[i]++; else 
            a[i]--;
            if (a[i]==n) a[i]=0; 
            if (a[i]==-1) a[i]=n-1;
        }
        x=0;
        for (int i=0; i<n; i++)
            if (a[i]!=i) {x=1; break;}
        if (x==0) {cout<<"yes"; return 0;}
        
    }

    cout<<"no";


    return 0;
}