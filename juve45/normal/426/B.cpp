#include <bits/stdc++.h>

using namespace std;

string s[120];
int n, m, k, a, b;
int dei(int k)
{
    if(k%2==1)
    return k;
    else{
    for(int i=1;i<=k/2;i++)
        if(s[i]!=s[k-i+1])
            return k;
        return dei(k/2);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>k;
            char c=k+'0';
            s[i].insert(s[i].end(), c);
        }

    cout<<dei(n);

    return 0;
}