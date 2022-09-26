#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
using namespace std;

typedef long long ll;

#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n, x;
        cin>>n>>x;
        vector<int> v(n);
        for (int i=0; i<n; i++)
            cin>>v[i];
        sort(v.begin(), v.end());
        int s=0;
        int j=0;
        for (int i=n-1; i>=0; i--){
            s+=v[i];
            if (s<x*(j+1))
                break;
            j++;
        }
        cout<<j<<"\n";
    }
    return 0;
}