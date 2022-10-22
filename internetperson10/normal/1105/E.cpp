#include <bits/stdc++.h>

using namespace std;

bool deps[41][41];
int best[1048577];
bool good[41];
set<int> curr;
vector<int> curry;
map<string, int> names;

void print_mat(int i) {
    for(int j = 0; j < i; j++) {
        for(int k = 0; k < i; k++) {
            cout << deps[j][k] << ' ';
        }
        cout << '\n';
    }
}

void update() {
    for(int i : curr) {
        curry.push_back(i);
    }
    for(int i = 0; i < curry.size(); i++) {
        for(int j = i+1; j < curry.size(); j++) {
            deps[curry[i]][curry[j]] = deps[curry[j]][curry[i]] = true;
        }
    }
    vector<int>().swap(curry);
    set<int>().swap(curr);
}

bool checkGood() {
    for(int j = 0; j < curry.size(); j++) {
        for(int k = j+1; k < curry.size(); k++) {
            if(deps[curry[j]][curry[k]]) return false;
        }
    }
    return true;
}

int main() {
    int n, q, x = 0, c, ans = 0;
    string s;
    cin >> q >> n;
    while(q--) {
        cin >> c;
        if(c == 1 && curr.size()) {
            update();
        }
        else if(c > 1) {
            cin >> s;
            if(names.find(s) == names.end()) {
                names[s] = x;
                deps[x][x] = true;
                x++;
            }
            curr.insert(names[s]);
        }
    }
    update();
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int a = n/2;
    int b = n - a;
    swap(a, b);
    best[0] = 0;
    for(int i = 1; i < (1 << a); i++) {
        for(int j = 0; j < a; j++) {
            if(i & (1 << j)) curry.push_back(j);
        }
        for(int k = 0; k < curry.size(); k++) {
            int y = i;
            int p = curry[k];
            for(int l = 0; l < a; l++) {
                if(deps[l][p]) y &= ((1 << a) - 1 - (1 << l));
            }
            best[i] = max(best[i], 1 + best[y]);
        }
        // for(int j = 0; j < curry.size(); j++) {
        //     cout << curry[j] << ' ';
        // }
        // cout << best[i] << '\n';
        ans = max(best[i], ans);
        vector<int>().swap(curry);
    }
    for(int i = 0; i < (1 << b); i++) {
        vector<int>().swap(curry);
        bool sad = false;
        for(int j = 0; j < b; j++) {
            if(i & (1 << j)) curry.push_back(j+a);
        }
        if(!checkGood()) continue;
        int y = (1 << a) - 1;
        for(int k = 0; k < curry.size(); k++) {
            int p = curry[k];
            for(int l = 0; l < a; l++) {
                if(deps[l][p]) y &= ((1 << a) - 1 - (1 << l));
            }
        }
        // for(int j = 0; j < curry.size(); j++) {
        //     cout << curry[j] << ' ';
        // }
        // for(int j = a-1; j >= 0; j--) {
        //     if((1 << j) & y) cout << 1;
        //     else cout << 0;
        // }
        // cout << ' ' << curry.size() + best[y] << '\n';
        ans = max(ans, (int)curry.size() + best[y]);
    }
    cout << ans << '\n';
}