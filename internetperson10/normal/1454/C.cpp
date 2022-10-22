#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll MOD = 1111169;
vector<ll> num, nums;
map<int, vector<int> > numbers;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, k, a = 0, ma = 999999999;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x;
            numbers[x].push_back(i);
        }
        for(auto p : numbers) {
            a = 0;
            k = -1;
            for(int i = 0; i < p.second.size(); i++) {
                if(p.second[i] - k > 1) a++;
                k = p.second[i];
            }
            if(n - k > 1) a++;
            if(a < ma) ma = a;
        }
        cout << ma << '\n';
        map<int, vector<int> >().swap(numbers);
    }
}