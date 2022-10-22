#include <bits/stdc++.h>
using namespace std;

char a[100],b[100];

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    cin>>a>>b;
    int n=strlen(b),i,k=0;
    for(i=0;i<n;i++){
        if(a[k]==b[i])k++;
    }
    cout<<k+1;
    return 0;
}