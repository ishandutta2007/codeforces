#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int count[26] = {0};
    for (char c : s) {
        count[c - 'a']++;
    }

    deque<char> dq;
    vector<char> result;

    int smallest = 0;
    for (char c : s) {
        while (count[smallest] == 0) smallest++;
        count[c - 'a']--;

        while (!dq.empty() && dq.back() - 'a' <= smallest) {
            result.push_back(dq.back());
            dq.pop_back();
        }
        dq.push_back(c);
        while (!dq.empty() && dq.back() - 'a' <= smallest) {
            result.push_back(dq.back());
            dq.pop_back();
        }
    }

    while (!dq.empty()) {
        result.push_back(dq.back());
        dq.pop_back();
    }

    cout << string(result.begin(), result.end()) << endl;

}