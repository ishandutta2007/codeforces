#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=4e6+100;
//typedef long long ll;
//#define int ll

int t[nmax];

void upd(int v, int l, int r, int pos, int val){
//    cout<<v<<" "<<l<<" "<<r<<" "<<pos<<"\n";
    if (l==r)
    {
        t[v]+=val;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(2*v, l, m, pos, val);
    else upd(2*v+1, m+1, r, pos, val);
    t[v]=t[2*v]+t[2*v+1];
}

int kth(int v, int l, int r, int k){
//    cout<<v<<" "<<l<<" "<<r<<" "<<k<<"\n";
    if (l==r)
        return l;
    int sl=t[2*v];
    if (sl>=k) return kth(2*v, l, (l+r)/2, k);
    else return kth(2*v+1, (l+r)/2+1, r, k-sl);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<fixed<<setprecision(10);

    int ttt=1;
//    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n, q;
        cin>>n>>q;
        for (int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            upd(1, 1, n, x, 1);
        }
        for (int i=1; i<=q; i++){
            int x;
            cin>>x;
            if (x<0)
                upd(1, 1, n, kth(1, 1, n, -x), -1);
            else
                upd(1, 1, n, x, 1);
        }
        if (t[1]==0)
            cout<<0<<"\n";
        else cout<<kth(1, 1, n, 1)<<"\n";
    }

    return 0;
}