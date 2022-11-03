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
    vector<int> a(n), b(1000000, 0);
    int mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > mx){
            cout << i + 1 << endl;
            return 0;
        }
        if(a[i] < b.size()){
            ++b[a[i]];
            while(b[mx]){
                ++mx;
            }
        }
    }
    cout << -1 << endl;


}