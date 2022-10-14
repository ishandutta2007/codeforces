#include<bits/stdc++.h>
#define maxn 1005
#define db(x) cerr<<#x<<": "<<(x)<<'\n'
using namespace std;

int n,m,a[11],b[11];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >>a[i];

    for(int i=1; i<=m; i++)
        cin >> b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j]) cout << a[i]<<' ';

    cout<<'\n';

return 0;
}