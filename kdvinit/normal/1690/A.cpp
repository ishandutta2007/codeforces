#include <iostream>
using namespace std;

void solve()
{
    int n; cin>>n;
    n-=6;
    int ans = 3 + (n+2)/3;
    
    int h1 = 2 + (n/3);
    int h2 = 3 + (n/3);
    int h3 = 1 + (n/3);
    
    if(n%3>0) h2++;
    if(n%3>1) h1++;
    
    cout<<h1<<" "<<h2<<" "<<h3<<endl;
}

int main() 
{
    int t; cin>>t;
    while(t--) solve();
}