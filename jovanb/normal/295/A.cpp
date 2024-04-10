#include <bits/stdc++.h>
using namespace std;

const int N=100005;

struct oper{
    long long l,r,x;
} operejshn[N];

long long br[N];
long long niz[N];
long long me[N];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long tren=0,n,m,k,i,le,ri;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)cin>>niz[i];
    for(i=1;i<=m;i++)cin>>operejshn[i].l>>operejshn[i].r>>operejshn[i].x;
    for(i=1;i<=k;i++){
        cin>>le>>ri;
        br[le]++;
        br[ri+1]--;
    }
    for(i=1;i<=m;i++){
        tren+=br[i];
        me[operejshn[i].l]+=tren*operejshn[i].x;
        me[operejshn[i].r+1]-=tren*operejshn[i].x;
    }
    tren=0;
    for(i=1;i<=n;i++){
        tren+=me[i];
        cout<<niz[i]+tren<<" ";
    }
    return 0;
}