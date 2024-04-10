#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,k,brx;
    cin>>n>>k;
    brx=(n-1)/2+1;
    if(k<=brx)cout<<k*2-1;
    else cout<<(k-brx)*2;
    return 0;
}