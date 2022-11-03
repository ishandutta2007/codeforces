#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<char> q;
    for(int i = 0; i < s.length(); ++i, --n){
        if(n & 1){
            q.push_back(s[i]);
        }else{
            q.push_front(s[i]);
        }
    }
    for(int i = 0; i < s.length(); ++i){
        cout << q.front();
        q.pop_front();
    }
    cout << endl;
}