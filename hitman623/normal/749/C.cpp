#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,d=0,r=0,dd=0,rr=0,ddd[200000],rrr[200000],re,de;
    char a[200001];
    cin>>n>>a;
    for(i=0;i<n;++i)
    {
        if(a[i]=='D') d++;
        else r++;
    }
    while(1)
    {
        for(i=0;i<n;++i)
    { 
        if(r==0) {cout<<"D";exit(0);}
        if(d==0) {cout<<"R";exit(0);}
        if(a[i]=='D')
        {
            if(dd==0) {r--;rr--;}
            else {dd++;a[i]='o';}
        }
        else if(a[i]=='R')
        {
            if(rr==0) {d--;dd--;}
            else {rr++;a[i]='o';}
        }
    }
    }
    return 0;
}