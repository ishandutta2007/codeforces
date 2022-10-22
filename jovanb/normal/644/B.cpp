#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll res[200005];
ll a[200005];
ll b[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    ll tm = 0, tm1 = 0;
    queue <int> q;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        tm = max(tm, a[i]);
        while(!q.empty()){
            int v = q.front();
            tm1 = max(tm1, a[v]);
            if(tm1 + b[v] <= tm){
                res[v] = tm1 + b[v];
                tm1 += b[v];
                q.pop();
            }
            else break;
        }
        if(q.size() > k) res[i] = -1;
        else q.push(i);
    }
    while(!q.empty()){
        int v = q.front();
        tm1 = max(tm1, a[v]);
        res[v] = tm1 + b[v];
        tm1 += b[v];
        q.pop();
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}