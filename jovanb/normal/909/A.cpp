#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    char a[100],b[100];
    cin>>a>>b;
    cout<<a[0];
    int i=1;
    int k=strlen(a);
    while(i<k && a[i++]<b[0])cout<<a[i-1];
    cout<<b[0];
    return 0;
}