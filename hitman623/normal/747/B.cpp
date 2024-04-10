#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,i,a=0,c=0,g=0,t=0;
    char x[256];
    cin>>n;
    cin>>x;
    for(i=0;i<n;++i)
        {if(x[i]=='G') g++;
        else if(x[i]=='C')c++;
        else if(x[i]=='A') a++;
        else if(x[i]=='T')t++;}
        g=n/4-g;
        a=n/4-a;
        c=n/4-c;
        t=n/4-t;
        if(n%4!=0 || a<0 || g<0 || c<0 || t<0) {cout<<"===";exit(0);}
    for(i=0;i<n;++i)
    {
        if(x[i]=='?')
        {
            if(g>0) {x[i]='G';g--;}
           else if(c>0) {x[i]='C';c--;}
            else if(t>0) {x[i]='T';t--;}
            else if(a>0) {x[i]='A';a--;}
        }
    }
    cout<<x;
    return 0;
}