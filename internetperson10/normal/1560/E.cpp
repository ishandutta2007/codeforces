#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

map<char, int> occ;
vector<char> vec;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(occ.find(s.at(i)) == occ.end()) {
                occ[s.at(i)] = 1;
                vec.push_back(s.at(i));
            }
            else occ[s.at(i)]++;
        }
        int len = 0;
        bool sad = false;
        for(int i = 0; i < vec.size(); i++) {
            if(occ[vec[i]]%(vec.size() - i)) {
                sad = true;
            }
            else len += (occ[vec[i]] / (vec.size() - i));
        }
        if(sad) {
            cout << -1 << '\n';
        }
        else {
            string currStr = s.substr(0, len);
            int i = 0;
            int currLen = len;
            reverse(vec.begin(), vec.end());
            for(int j = 0; j < vec.size(); j++) {
                for(int k = 0; k < currLen; k++) {
                    if(i == s.size()) sad = true;
                    else if(currStr.at(k) != s.at(i)) sad = true;
                    else i++;
                }
                currStr.erase(remove(currStr.begin(), currStr.end(), vec[j]), currStr.end());
                currLen = currStr.size();
            }
            if(sad) cout << -1 << '\n';
            else {
                cout << s.substr(0, len) << ' ';
                for(int j = 0; j < vec.size(); j++) cout << vec[j];
                cout << '\n';
            }
        }
        vector<char>().swap(vec);
        map<char, int>().swap(occ);
    }
}