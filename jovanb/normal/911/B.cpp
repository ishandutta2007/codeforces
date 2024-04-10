#include <bits/stdc++.h>

using namespace std;
long a1[1000],b1[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,a,b,i=0;
    cin>>n>>a>>b;
    for(i=1;i<n;i++){
        a1[i]=a/i;
        b1[i]=b/(n-i);
    }
    long brmax=0;
    for(i=1;i<n;i++){
        brmax=max(min(a1[i],b1[i]),brmax);
    }
    cout<<brmax;
    return 0;
}