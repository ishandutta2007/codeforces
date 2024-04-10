#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long d,k,l,m,n,i,br=0;
    cin>>k>>l>>m>>n>>d;
    for(i=1;i<=d;i++){
        if(i%k==0 || i%l==0 || i%m==0 || i%n==0)br++;
    }
    cout<<br;
    return 0;
}