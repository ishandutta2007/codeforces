#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

bool digit(char c){
    return c >= '0' && c <= '9';
}

vector<ll> pows;

ll getval(string s){
    ll cur = 0;
    for(int i = 1; i < s.length(); ++i){
        cur += pows[i];
    }
    for(int i = 0; i < s.length(); ++i){
        cur += pows[(int)s.length() - 1 - i] * (s[i] - 'A');
    }
    ++cur;
    return cur;
}

string getStr(ll val){
    int len = 1;
    --val;
    while(val >= pows[len]){
        val -= pows[len++];
    }
    string s(len, 'A');
    for(int i = 0; i < len; ++i){
        while(val >= pows[len - 1 - i]){
            val -= pows[len - 1 - i];
            ++s[i];
        }
    }
    return s;
}


string parse(string& s){
    vector<int> breaks;
    for(int i = 1; i < s.length(); ++i){
        if(digit(s[i]) ^ digit(s[i - 1])){
            breaks.push_back(i);
        }
    }
    if(breaks.size() == 1){
        ll one = getval(s.substr(0, breaks[0]));
        ll two = atoi(s.substr(breaks[0], (int)s.length() - breaks[0]).c_str());
        return "R" + to_string(two) + "C" + to_string(one);
    }else{
       // ll one = atoi(s.substr(breaks[0], (int)breaks[1] - breaks[0]).c_str());
        ll two = atoi(s.substr(breaks[2], (int)s.length() - breaks[2]).c_str());
        return getStr(two) + s.substr(breaks[0], (int)breaks[1] - breaks[0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    pows.push_back(1);
    for(int i = 0; i < 10; ++i){
        pows.push_back(pows.back() * 26);
    }
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        cout << parse(s) << "\n";
    }

}