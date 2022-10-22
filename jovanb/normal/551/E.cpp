#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 500000;
const int K = 650;

ll a[N+5];
pair <ll, int> s[N+5];

ll lazy[N+5];
int L[N+5], R[N+5];

pair <int, int> trazi(int block, ll y){
    int l = L[block], r = R[block], prvi = R[block]+1;
    while(l <= r){
        int mid = (l+r)/2;
        ll val = lazy[block] + s[mid].first;
        if(val >= y){
            prvi = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(prvi > R[block] || lazy[block] + s[prvi].first != y) return {0, 0};
    l = L[block], r = R[block];
    int poslednji = 0;
    while(l <= r){
        int mid = (l+r)/2;
        ll val = lazy[block] + s[mid].first;
        if(val <= y){
            poslednji = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return {s[prvi].second, s[poslednji].second};
}

int block[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs;
    for(int i=1; i<=n; i++) L[i] = n+5;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        s[i] = {a[i], i};
        block[i] = 1 + i/K;
        L[block[i]] = min(L[block[i]], i);
        R[block[i]] = max(R[block[i]], i);
    }
    for(int i=1; i<=1+n/K; i++) sort(s+L[i], s+R[i]+1);
    while(qrs--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int l, r, x;
            cin >> l >> r >> x;
            int mnl = r+1, mxr = l-1;
            for(int i=block[l]; i<=block[r]; i++){
                if(l <= L[i] && R[i] <= r){
                    mnl = min(mnl, L[i]);
                    mxr = max(mxr, R[i]);
                    lazy[i] += x;
                }
            }
            for(int i=l; i<mnl; i++){
                mxr = max(mxr, i);
                a[i] += x;
            }
            for(int i=r; i>mxr; i--){
                a[i] += x;
            }
            for(int i=L[block[l]]; i<=R[block[l]]; i++){
                a[i] += lazy[block[l]];
                s[i] = {a[i], i};
            }
            lazy[block[l]] = 0;
            sort(s+L[block[l]], s+R[block[l]]+1);
            if(block[r] == block[l]) continue;
            for(int i=L[block[r]]; i<=R[block[r]]; i++){
                a[i] += lazy[block[r]];
                s[i] = {a[i], i};
            }
            lazy[block[r]] = 0;
            sort(s+L[block[r]], s+R[block[r]]+1);
        }
        else{
            int y;
            cin >> y;
            int mn = n+1, mx = 0;
            for(int bl=1; bl<=1+n/K; bl++){
                pair <int, int> pr = trazi(bl, y);
                if(pr.first){
                    mn = min(mn, pr.first);
                    mx = max(mx, pr.second);
                    break;
                }
            }
            for(int bl=1+n/K; bl>=1; bl--){
                pair <int, int> pr = trazi(bl, y);
                if(pr.first){
                    mn = min(mn, pr.first);
                    mx = max(mx, pr.second);
                    break;
                }
            }
            if(mn > mx) cout << "-1\n";
            else cout << mx - mn << "\n";
        }
    }
    return 0;
}