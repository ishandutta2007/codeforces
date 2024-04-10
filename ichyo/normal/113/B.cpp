#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef unsigned long long ULL;

template<ULL B>
struct RHash{
    vector<ULL> pow; 
    vector<ULL> hash;
    RHash(const string& s) {
        int n = s.size();
        pow.assign(n + 1, 1);
        hash.assign(n + 1, 0);
        REP(i, n) {
            pow[i + 1] = pow[i] * B;
            hash[i + 1] = s[i] + hash[i] * B;
        }
    }
    // hash of s[0..i)
    ULL h(int i) {
        return hash[i];
    }
    // hash of s[i..j)
    ULL h(int i, int j) {
        return h(j) - h(i) * pow[j-i];
    }
};

template<int B, int M>
struct RMHash{
    vector<int> pow;
    vector<int> hash;
    RMHash(const string& s) {
        int n = s.size();
        pow.assign(n + 1, 1);
        hash.assign(n + 1, 0);
        REP(i, n) {
            pow[i + 1] = ((long long)pow[i] * B) % M;
            hash[i + 1] = (s[i] + (long long)hash[i] * B % M) % M;
        }
    }
    // hash of s[0..i)
    int h(int i) {
        return hash[i];
    }
    // hash of s[i..j)
    int h(int i, int j) {
        return (h(j) + M - (long long)h(i) * pow[j-i] % M) % M;
    }
};

typedef RMHash<10007, 1000000009> Hash1;
typedef RMHash<10009, 1000000007> Hash2;

int main(){
    string s, a, b;
    cin >> s >> a >> b;
    int n = s.size();
    int al = a.size();
    int bl = b.size();
    vector<int> begin;
    vector<int> end;
    REP(i, n) if(i + al <= n && a == s.substr(i, al)) begin.push_back(i);
    REP(i, n) if(i + bl <= n && b == s.substr(i, bl)) end.push_back(i + bl);

    Hash1 S1(s);
    Hash2 S2(s);
    unordered_set<ULL> st;
    for(int bg : begin) for(int ed : end) if(bg <= ed - bl && bg + al <= ed) {
        st.insert(((ULL)S1.h(bg, ed) << 32) + S2.h(bg, ed));
    }

    cout << st.size() << endl;
    return 0;
}