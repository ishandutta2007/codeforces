#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,t=0;
    cin>>a>>b;
    while(a>0 && b>0 && (a!=1 || b!=1)){
        if(a<=b){a++;b-=2;}
        else{b++;a-=2;}
        t++;
    }
    cout<<t;
    return 0;
}