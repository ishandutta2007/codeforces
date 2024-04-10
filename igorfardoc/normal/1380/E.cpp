#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<set<int>> a(m);
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[val - 1].insert(i);
    }
    int now = 0;
    for(int i = 0; i < m; i++) {
        for(const auto& el : a[i]) {
            now += a[i].find(el + 1) != a[i].end();
        }
    }
    cout << n - 1 - now << '\n';
    vector<set<int>*> b(m);
    for(int i = 0; i < m; i++) {
        b[i] = &a[i];
    }
    for(int i = 0; i < m - 1; i++) {
        int fir, sec;
        cin >> fir >> sec;
        --fir;
        --sec;
        int to = fir;
        if(b[fir]->size() > b[sec]->size()) {
            swap(fir, sec);
        }
        for(const auto& el : *(b[fir])) {
            now += b[sec]->find(el + 1) != b[sec]->end();
            now += b[sec]->find(el - 1) != b[sec]->end();
        }
        for(const auto& el : *(b[fir])) {
            b[sec]->insert(el);
        }
        b[to] = b[sec];
        cout << n - 1 - now << '\n';
    }
}