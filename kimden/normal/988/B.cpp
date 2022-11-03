#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool len(string& a, string& b){
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    sort(all(s), len);
    for(int i = 0; i < n - 1; ++i){
        if(s[i + 1].find(s[i]) == string::npos){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(auto& a: s){
        cout << a << endl;
    }

}