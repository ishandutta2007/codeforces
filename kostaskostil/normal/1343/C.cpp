#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200500];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        pair<int, int> neg={0, 0}, pos={0, 0};
        for (int i=1; i<=n; i++)
            if (a[i]>0)
                pos=max(pos, {neg.first+1, neg.second+a[i]});
            else
                neg=max(neg, {pos.first+1, pos.second+a[i]});
        cout<<max(neg, pos).second<<"\n";
    }
}