#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];

priority_queue <int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        pq.push(-niz[i]);
    }
    sort(niz+1, niz+1+n);
    int ukup=0;
    for(int i=1; i<=n; i++){
        while(!pq.empty()){
            int a = -pq.top();
            pq.pop();
            if(a > niz[i]){ukup++; break;}
        }
    }
    cout << ukup;
    return 0;
}