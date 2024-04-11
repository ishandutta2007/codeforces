#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=5e5+100;

int a, b, q;
int isg[40100];

int f(int r){
    return (r/(a*b))*isg[a*b] + isg[r%(a*b)];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for (int j=0; j<t; j++)
    {
        cin>>a>>b>>q;
        for (int i=0; i<a*b; i++)
            if ((i%a)%b != (i%b)%a) isg[i]=1;
            else isg[i]=0;
        for (int i=1; i<a*b; i++)
            isg[i]+=isg[i-1];
        isg[a*b]=isg[a*b-1];
        if (a<b) swap(a, b);
        for (int i=0; i<q; i++)
        {
            int l, r;
            cin>>l>>r;
            cout<<f(r)-f(l-1)<<" ";
        }
        cout<<"\n";
    }
}