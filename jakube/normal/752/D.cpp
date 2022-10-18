#include <bits/stdc++.h>
using namespace std;

// class Node {
//     public:
//         vector<Node*> v;
//         vector<int> data;
//         Node() {
//             v.assign(26, nullptr);
//         }

//         Node* add(char c) {
//             if (v[c-'a'] != nullptr) 
//                 return v[c-'a'];
//             else 
//                 return v[c-'a'] = new Node();
//         }

//         void getData()
// };


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int k, n;
    cin >> k >> n;
    
    vector<string> ss(k);
    vector<int> a(k);
    for (int idx = 0; idx < k; idx++)
        cin >> ss[idx] >> a[idx];
    
    map<string, vector<int>> m;
    for (int i = 0; i < k; i++) {
        m[ss[i]].push_back(a[i]);
    }

    long long result = 0;
    set<string> palindroms;
    for (auto& p : m) {
        string s = p.first;
        vector<int> as = p.second;;

        string rev(s.rbegin(), s.rend());

        if (s == rev) {
            palindroms.insert(s);
        } else if (m.count(rev)) {
            vector<int> bs = m[rev];
            sort(as.rbegin(), as.rend());
            sort(bs.rbegin(), bs.rend());

            for (int i = 0; i < min(as.size(), bs.size()); i++) {
                if (as[i] + bs[i] > 0) {
                    result += as[i] + bs[i];
                }
            }
        }
    }
    result /= 2;
    
    int middle = 0;
    for (auto s : palindroms) {
        vector<int> as = m[s];

        sort(as.rbegin(), as.rend());
        for (int i = 0; i+1 < as.size(); i+=2) {
            if (as[i] + as[i+1] > 0) {
                result += as[i] + as[i+1];
                if (as[i+1] < 0) {
                    middle = max(middle, -as[i+1]);
                }
            }
            else if (as[i] > 0) {
                middle = max(middle, as[i]);
            }
        }
        if (as.size() & 1) {
            middle = max(middle, as.back());
        }
    }

    result += middle;
    
    
    cout << result << endl;



    return 0;
}