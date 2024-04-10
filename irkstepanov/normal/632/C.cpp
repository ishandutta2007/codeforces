#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

bool comp(const string& a, const string& b)
{
    return a + b < b + a;
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    sort(all(v), comp);
    for (int i = 0; i < n; ++i) {
        cout << v[i];
    }
    cout << "\n";
    
}