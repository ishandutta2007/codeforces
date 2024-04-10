#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define push_back pb

pair <int, int> niz[100005];

bool cmp(pair <int, int> a, pair <int, int> b){
    if(abs(a.first) == abs(b.first)) return abs(a.second) < abs(b.second);
    return abs(a.first) < abs(b.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
    
    int n;
    cin >> n;
    queue <int> types;
    queue <int> br;
    queue <char> dir;
    for(int i=1; i<=n; i++){
        cin >> niz[i].first >> niz[i].second;
    }
    sort(niz+1, niz+1+n, cmp);
    for(int i=1; i<=n; i++){
        int x = niz[i].first;
        int y = niz[i].second;
        if(x){
            types.push(1);
            br.push(x);
            if(x > 0) dir.push('R');
            else dir.push('L');
        }
        if(y){
            types.push(1);
            br.push(y);
            if(y > 0) dir.push('U');
            else dir.push('D');
        }
        types.push(2);
        br.push(0);
        dir.push('A');
        if(x){
            types.push(1);
            br.push(x);
            if(x > 0) dir.push('L');
            else dir.push('R');
        }
        if(y){
            types.push(1);
            br.push(y);
            if(y > 0) dir.push('D');
            else dir.push('U');
        }
        types.push(3);
        br.push(0);
        dir.push('A');
    }
    cout << types.size() << "\n";
    while(!types.empty()){
        int tip = types.front();
        cout << tip;
        if(tip-1){
            types.pop();
            br.pop();
            dir.pop();
            cout << "\n";
            continue;
        }
        cout << " " << abs(br.front()) << " " << dir.front() << "\n";
        types.pop();
        br.pop();
        dir.pop();
    }
    return 0;
}