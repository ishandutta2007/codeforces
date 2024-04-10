#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    ll res = 0;
    priority_queue <int> pq;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(!pq.empty() && -pq.top() < x){
            int k = -pq.top();
            res += x-k;
            pq.pop();
            pq.push(-x);
        }
        pq.push(-x);
    }
    cout << res;
    return 0;
}