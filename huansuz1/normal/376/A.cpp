#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>
#define ll long long

using namespace std;

string s;
long long x[1234560][2],y[1234506][2],n,l1,l2,p=0,q,ar[1234506];
long long a,b;


int main()
{
    cin>>s;
    for (int i=0; i<s.length(); i++)
        if (s[i]=='^') {p=i; break ;}

    for (int i=p; i>=0; i--) 
        if (s[i]>='0' && s[i]<='9') {
            x[l1][0]=s[i]-'0';   
            x[l1][1]=p-i;
            l1++;
        }
    for (int i=p; i<s.length(); i++) 
        if (s[i]>='0' && s[i]<='9') {
            y[l2][0]=s[i]-'0';   
            y[l2][1]=i-p;
            l2++;
        }



    
    for (int i=0; i<l1; i++)
        a+=(x[i][0]*(x[i][1]));
    for (int j=0; j<l2; j++)
        b+=(y[j][0]*(y[j][1]));


    if (a==b) {cout<<"balance"; return 0;}
    if (a>b) cout<<"left"; else cout<<"right";

    
    return 0;
}