#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prime(int x){
    if(x < 2) return 0;
    for(int i=2; i*i<=x; i++){
        if(x%i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    queue <pair <int, int> > q;
    int e = 0;
    for(int i=1; i<n; i++){
        q.push({i, i+1});
        e++;
    }
    q.push({n, 1});
    e++;
    int tren = 1;
    while(!prime(e)){
        e++;
        q.push({tren, n-tren});
        tren++;
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }
    return 0;
}