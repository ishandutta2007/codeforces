#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[3];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>f[0]>>f[1];
        int n;
        cin>>n;
        f[2]=f[0]^f[1];
        printf("%d\n",f[n%3]);
    }
}