#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
int n,k,l,c,d,p,nl,np,ans;
int main()
{
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int m=k*l/nl,lim=c*d,sal=p/np;
    cout<<(min(min(m,lim),sal))/n;

    return 0;
}