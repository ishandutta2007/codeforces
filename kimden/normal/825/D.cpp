#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    vector<int> v(26, 0), w(26, 0);
    int que = 0;
    cin >> s >> t;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '?'){
            ++que;
        }else{
            ++v[s[i] - 'a'];
        }
    }
    if(que == 0){
        cout << s << endl;
        return 0;
    }
    for(int i = 0; i < t.length(); ++i){
        ++w[t[i] - 'a'];
    }
    string add = "";
    int mn = s.length() + 1;
    int mx = 0;
    for(int i = 0; i < 26; ++i){
        if(w[i] == 0){
            continue;
        }
        mn = min(mn, v[i] / w[i]);
        mx = max(mx, (v[i] + w[i] - 1) / w[i]);
    }
    vector<pair<int, string>> events;
    for(int i = 0; i < 26; ++i){
        if(w[i] == 0){
            continue;
        }
        string tmp = "";
        string tmp2 = "";
        if(v[i] % w[i] != 0){
            tmp.resize(w[i] - (v[i] % w[i]), (char)('a' + i));
            v[i] += w[i] - (v[i] % w[i]);
            tmp2.resize(w[i] - tmp.length(), (char)('a' + i));
            ll x = v[i] / w[i];
            events.push_back({x, tmp});
            events.push_back({x + 1, tmp2});
        }else{
            tmp2.resize(w[i], (char)('a' + i));
            ll x = v[i] / w[i];
            events.push_back({x + 1, tmp2});
        }
    }
    sort(events.begin(), events.end());
    string str = "";
    int ptr = 0;
    int cur = mn + 1;
    int ptrev = 0;
    while(ptrev < events.size() && events[ptrev].first <= cur){
        str += events[ptrev].second;
        ++ptrev;
    }
    for(int i = 0; i < s.length() && que > 0; ++i){
        if(s[i] != '?'){
            continue;
        }
        if(str.empty() || ptr == str.length()){
            ++cur;
            ptr = 0;
            while (ptrev < events.size() && events[ptrev].first <= cur) {
                str += events[ptrev].second;
                ++ptrev;
            }
        }
        s[i] = str[ptr];
        ++ptr;
        --que;
    }
    cout << s << endl;
    return 0;
}