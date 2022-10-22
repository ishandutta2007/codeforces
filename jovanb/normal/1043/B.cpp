#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

queue <int> q;
int niz[10005];
int tren[10005];

int n;

const int INF = 1000000000;

bool moze(int len){
    for(int i=0; i<len; i++) tren[i] = INF;
    for(int i=1; i<=n; i++){
        int k = (i-1)%len;
        if(tren[k] == INF){
            tren[k] = niz[i]-niz[i-1];
        }
        else if(tren[k] != niz[i]-niz[i-1]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int len=1; len<=n; len++){
        if(moze(len)) q.push(len);
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}