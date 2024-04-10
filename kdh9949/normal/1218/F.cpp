#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 100005;

int n, k, a, x[N];
ll r;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i];
    cin >> a;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        pq.push(t);
        while(k < x[i]){
            if(pq.empty()){ cout << "-1\n"; return 0; }
            r += pq.top();
            k += a;
            pq.pop();
        }
    }
    cout << r << '\n';
}