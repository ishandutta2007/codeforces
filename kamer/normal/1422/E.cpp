#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
typedef long long ll;

void push_chars(deque<tuple<char, int>>& chars, char c) {
    if (chars.empty()) {
        chars.push_front(make_tuple(c, 1));
    } else {
        auto ccc = chars[0];
        char cc = get<0>(ccc);
        int count = get<1>(ccc);
        if (c == cc) {
            chars.pop_front();
            chars.push_front(make_tuple(c, count + 1));
        } else {
            chars.push_front(make_tuple(c, 1));
        }
    }
}

void pop_chars(deque<tuple<char, int>>& chars) {
    auto cc = chars[0];
    char c = get<0>(cc);
    int count = get<1>(cc);
    if (count == 1) {
        chars.pop_front();
    } else {
        chars.pop_front();
        chars.push_front(make_tuple(c, count - 1));
    }
}

bool should_push(deque<tuple<char, int>>& chars, char c) {
    if (chars.size() == 1) {
        return false;
    }

    auto ccc = chars[1];
    char cc = get<0>(ccc);
    if (cc < c) {
        return false;
    } else {
        return true;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<tuple<int, string>> answers(n);
    deque<char> curr;
    deque<tuple<char, int>> chars;
    bool hasLast = true;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            curr.push_front(s[i]);
            push_chars(chars, s[i]);
            hasLast = true;
        } else {
            if (s[i] != s[i + 1]) {
                curr.push_front(s[i]);
                push_chars(chars, s[i]);
                hasLast = true;
            } else {
                if (!hasLast) {
                    curr.push_front(s[i]);
                    push_chars(chars, s[i]);
                    hasLast = true;
                } else {
                    if (should_push(chars, s[i])) {
                        curr.push_front(s[i]);
                        push_chars(chars, s[i]);
                        hasLast = true;
                    } else {
                        curr.pop_front();
                        pop_chars(chars);
                        hasLast = false;
                    }
                }
            }
        }

        // Now make the answer
        int l = curr.size();
        if (l <= 10) {
            string ss = "";
            ss.resize(l);
            for (int j = 0; j < l; j++) ss[j] = curr[j];
            answers[i] = make_tuple(l, ss);
        } else {
            string ss = "";
            ss.resize(10);
            for (int j = 0; j < 5; j++) ss[j] = curr[j];
            ss[5] = '.';
            ss[6] = '.';
            ss[7] = '.';
            ss[8] = curr[l - 2];
            ss[9] = curr[l - 1];
            answers[i] = make_tuple(l, ss);
        }
    }

    for (int i = 0; i < n; i++) {
        auto ls = answers[i];
        int l = get<0>(ls);
        string ss = get<1>(ls);
        cout << l << " " << ss << "\n";
    }
}