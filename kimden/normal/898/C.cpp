#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


bool comp(string& a, string& b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() > b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string name, num;
    int k;
    map<string, vector<string>> mp;
    for(int i = 0; i < n; ++i){
        cin >> name;
        cin >> k;
        for(int j = 0; j < k; ++j){
            cin >> num;
            mp[name].push_back(num);
        }
    }
    for(auto& u: mp){
        sort(u.second.begin(), u.second.end(), comp);
    }
    cout << mp.size() << endl;
    for(auto u: mp){
        set<string> st;
        for(auto s: u.second){
            bool fail = false;
            for(auto q: st){
                if(s.length() <= q.length() && q.substr(q.length() - s.length(), s.length()) == s){
                    fail = true;
                    break;
                }
            }
            if(!fail){
                st.insert(s);
            }
        }

        cout << u.first << " " << st.size();
        for(auto q: st){
            cout << " " << q;
        }
        cout << endl;
    }

    return 0;
}