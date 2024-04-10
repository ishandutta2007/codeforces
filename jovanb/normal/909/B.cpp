#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n;
    cin>>n;
    cout<<ceil(n*1.0/2)*(n/2+1);
    return 0;
}