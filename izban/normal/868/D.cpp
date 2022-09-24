#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void print(vector<int> a) {
    for (int x : a) printf("%d\n", x);
}

const int K = 16;
const int N = 1 << (K + 1);
vector<char> check(string s) {
    int n = s.length();
    vector<char> res(N);
    for (int i = 0; i < n; i++) {
        int chash = 1;
        for (int j = i; j < n && j - i + 1 <= K; j++) {
            chash = 2 * chash + (s[j] - '0');
            res[chash] = 1;
        }
    }
    //cout << s << " " << (int)res[5] << endl;
    return res;
}

vector<char> comb(vector<char> a, vector<char> b) {
    for (int i = 0; i < N; i++) {
        a[i] |= b[i];
    }
    return a;
}

string concatPref(string a, string b) {
    string res = a + b;
    if ((int)res.length() > K) res = res.substr(0, K);
    return res;
}

string concatSuf(string a, string b) {
    string res = a + b;
    if ((int)res.length() > K) res = res.substr((int)res.length() - K, K);
    return res;
}

int findLen(const vector<char> &f) {
    for (int len = 1; len <= K; len++) {
        bool ok = 1;
        for (int i = 0; i < (1 << len); i++) {
            int cmask = (1 << len) + i;
            ok &= f[cmask];
        }
        if (!ok) return len - 1;
    }
    return K + 1;
}

vector<int> solve(vector<string> s, vector<int> a, vector<int> b) {
    int n = s.size();
    vector<string> pref(n), suf(n);
    for (int i = 0; i < n; i++) {
        int len = min((int)s[i].length(), K);
        pref[i] = s[i].substr(0, len);
        suf[i] = s[i].substr((int)s[i].length() - len, len);
    }

    vector<vector<char> > hasMask(n, vector<char>(N));
    for (int i = 0; i < n; i++) {
        hasMask[i] = check(s[i]);
    }


    int m = a.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        vector<char> cres = comb(hasMask[a[i]], hasMask[b[i]]);
        cres = comb(cres, check(suf[a[i]] + pref[b[i]]));
        //for (int j = 0; j < 10; j++) cout << (int)cres[j] << " "; cout << endl;
        hasMask.push_back(cres);
        pref.push_back(concatPref(pref[a[i]], pref[b[i]]));
        suf.push_back(concatSuf(suf[a[i]], suf[b[i]]));
        ans.push_back(findLen(cres));
    }
    return ans;
}

void test() {
    vector<string> s(1);
    for (int i = 0; i < 100; i++) {
        int cnt = 0;
        int x = i;
        while (x) {
            cnt += x % 2;
            x /= 2;
        }
        s[0] += (char)('0' + cnt % 2);
    }
    vector<int> a, b;
    for (int i = 0; i < 100; i++) {
        a.push_back(i);
        b.push_back(i);
    }

    //cout << s[0] << endl;
    solve(s, a, b);
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //test();

    int n;
    while (cin >> n) {
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int m;
        cin >> m;
        vector<int> a(m), b(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
        }

        print(solve(s, a, b));
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}