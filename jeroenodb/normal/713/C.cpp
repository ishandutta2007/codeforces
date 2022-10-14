#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    priority_queue<int> pq;
    ll ans=0;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        a-=i;
        pq.push(a), pq.push(a);
        ans+=abs(a-pq.top());
        pq.pop();
    }
    cout << ans << '\n';
}