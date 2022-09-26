#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

int n;
int a[nmax];
int x[nmax];
int y[nmax];

bool cando(){
    bool e=false;
    bool o=false;
    for (int i=1; i<=n; i++)
        if ((x[i]+y[i])%2==0)
            e=true;
        else
            o=true;
    if(e&o)
        return true;
    int r=(abs(x[1]-y[1])%2);
    for (int i=1; i<=n; i++){
        int xi=x[i]-y[i];
        int yi=x[i]+y[i];
        x[i]=(xi+r)/2;
        y[i]=(yi+r)/2;
    }
    return false;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x[i]>>y[i];

    while (!cando()){}
    for (int i=1; i<=n; i++)
        if (a[i]=(x[i]+y[i])%2);
    int cnt=0;
    for (int i=1; i<=n; i++)
        if (a[i]==0)
            cnt++;
    cout<<cnt<<"\n";
    for (int i=1; i<=n; i++)
        if (a[i]==0)
            cout<<i<<" ";
    cout<<"\n";

    return 0;
}