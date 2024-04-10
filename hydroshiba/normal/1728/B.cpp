#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

void brute(int n){
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    int ans = 0;

    do{
        int c = 0;
        for(int i : p){
            if(c < i) c += i;
            else c = 0;
        }

        if(c >= ans){
            ans = c;
            for(int i : p) cout << i << ' ';
            cout << c << endl;
        }
    }while(next_permutation(p.begin(), p.end()));
}

void solve(){
    int n;
    cin >> n;

    deque<int> q;
    q.push_back(n - 1);
    q.push_back(n);

    vector<bool> used(n + 1);
    int x = 0;

    for(int i = n - 2; i > 0; --i){
        if(x == 0){
            for(int j = 1; j <= n - 2; ++j) if(!used[j]){
                q.push_front(j); used[j] = 1; break;
            }
            x = 1;
        }
        else{
            for(int j = n - 2; j > 0; --j) if(!used[j]){
                q.push_front(j); used[j] = 1; break;
            }
            x = 0;
        }
    }

    for(int i : q) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //brute(7);

    int t;
    cin >> t;

    while(t--)
        solve();
}