#include <iostream>
#include <cstdio>

using namespace std;
int n;
long long m,x,y;

int main(){
    cin>>n;
    for (int i=0; i<n; i++)  {
        cin>>m;
        while(m%2==0){m/=2;}
        while(m%3==0){m/=3;}
        if (!x) x=m; else if (x!=m) {cout<<"NO"; return 0;}
    }
    cout<<"YES";
    return 0;
}