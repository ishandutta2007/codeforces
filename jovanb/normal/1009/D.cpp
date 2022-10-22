#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> resenje;

void autput(){
    cout << "Possible\n";
    for(auto c : resenje){
        cout << c.first << " " << c.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    if(m < n-1){cout << "Impossible"; return 0;}
    for(int i=2; i<=n; i++){
        resenje.push_back({1, i});
    }
    m -= n-1;
    if(m == 0){
        autput();
        return 0;
    }
    for(int i=2; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(__gcd(i, j) == 1){
                resenje.push_back({i, j});
                m--;
                if(m == 0) break;
            }
        }
        if(m == 0) break;
    }
    if(m > 0){
        cout << "Impossible\n";
    }
    else autput();
    return 0;
}