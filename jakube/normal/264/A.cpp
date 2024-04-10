#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    deque<int> l, r;
    for (int i = 0; i < s.size(); i++) { 
        if (s[i] == 'l')
            r.push_front(i+1);
        else
            l.push_back(i+1);
    }

    for (int i : l)
        cout << i << '\n';
    for (int i : r)
        cout << i << '\n';
}