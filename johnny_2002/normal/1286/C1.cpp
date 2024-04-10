#include <bits/stdc++.h>

using namespace std;

const int alp = 26;
vector<vector<int>> ask(int L, int R) {
    cout << "? " << L << " " << R << endl;
    int len = R - L + 1;
    int total = len * (len + 1) / 2;

    vector<vector<int>> ans;
    for(int i = 1; i <= total; i++) {
        string s;
        cin >> s;  
        vector<int> cur(alp, 0);
        for(auto ch : s) 
            cur[ch - 'a']++;
        ans.push_back(cur);
    }
    return ans;
}
vector<vector<int>> getRem(vector<vector<int>> a, vector<vector<int>> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    vector<vector<int>> res;
    for(int i = 0, j = 0; i < a.size(); i++) {
        if (j == b.size() || a[i] != b[j]) {
            res.push_back(a[i]);
        } else j++;
    }
    return res;
}
void answer(string s) {
    cout << "! " << s << endl;
    exit(0);
}
int main() {
    int n;
    cin >> n;
    auto all = ask(1, n);
    if (n == 1) {
        string res;
        int key = find(all[0].begin(), all[0].end(), 1) - all[0].begin();
        res.push_back('a' + key);
        answer(res);
    }
    auto neg = ask(2, n);
    auto use = getRem(all, neg);

    sort(use.begin(), use.end(), [](vector<int> &a, vector<int> &b) {
        int suma = 0; for(auto i : a) suma += i;
        int sumb = 0; for(auto i : b) sumb += i;
        return suma < sumb;
    });
    string res;

    for(int i = 0; i < n; i++) {
        int pos = find(use[i].begin(), use[i].end(), 1) - use[i].begin();
        for(int j = i; j < n; j++) use[j][pos]--;
        res.push_back('a' + pos);
    }
    answer(res);
}