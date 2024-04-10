#include <bits/stdc++.h>

using namespace std;
long long y,b,r,t;
int main()
{
    cin>>y>>b>>r;
    while(b>=r){
        b--;
    }
    while(y>=b){
        y--;

    }
    b=y+1;
    r=b+1;
    cout<<y+b+r<<endl;
}