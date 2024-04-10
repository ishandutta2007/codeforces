#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,i,br=1;
    char a[3],b[3];
    cin>>n;
    cin>>a;
    for(i=1;i<n;i++){
        cin>>b;
        if(b[0]==a[1])br++;
        a[0]=b[0];
        a[1]=b[1];
    }
    cout<<br;
    return 0;
}