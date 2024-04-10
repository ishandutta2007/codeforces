#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int ima[1000005];
const int s = 1000000;
queue <int> q;
queue <int> moze;
int niz[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        ima[niz[i]] = 1;
    }
    for(int i=1; i<=500000; i++){
        if(!ima[i] && !ima[s-i+1]) moze.push(i);
    }
    sort(niz+1, niz+1+n);
    for(int i=1; i<=n; i++){
        if(!ima[s+1-niz[i]]) q.push(s+1-niz[i]);
        else{
            if(s+1-niz[i] < niz[i]) continue;
            int x = moze.front();
            moze.pop();
            q.push(x);
            q.push(s-x+1);
        }
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}