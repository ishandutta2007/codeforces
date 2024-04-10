#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    if(2*k+1 >= n){cout << 1 << "\n" << min(n, k+1); return 0;}
    int x = 2*k+1;
    if(n%x == 0){
        cout << n/x << "\n";
        for(int i=k+1; i<=n; i+=x) cout << i << " ";
        return 0;
    }
    int ost = n%x;
    if(ost >= k+1){
        queue <int> q;
        for(int i=k+1; i<=n; i+=x) q.push(i);
        cout << q.size() << "\n";
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        return 0;
    }
    queue <int> q;
    for(int i=1; i<=n; i+=x) q.push(i);
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}