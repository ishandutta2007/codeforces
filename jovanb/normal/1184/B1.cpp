#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

pair <ll, ll> a[100005];
ll niz[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<=k; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+1+k);
    for(int i=2; i<=k; i++){
        a[i].second += a[i-1].second;
    }
    for(int i=1; i<=n; i++){
        int l=1, r=k, tr=0;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid].first <= niz[i]){
                l = mid+1;
                tr = mid;
            }
            else r = mid-1;
        }
        cout << a[tr].second << " ";
    }
    return 0;
}