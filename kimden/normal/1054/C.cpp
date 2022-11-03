#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n), r(n), a(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> r[i];
    }

    for(int i = 0; i < n; ++i){
        a[i] = n - l[i] - r[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(a[i] > a[j]){
                --l[j];
            } else if(a[i] < a[j]){
                --r[i];
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(l[i] != 0 || r[i] != 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;



}