#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    char word[22];
    unordered_map<string, int> pos;

    scanf("%d\n", &n);
    int last = n;
    while (n--) {
        scanf("%s\n", word);
        pos[word] = --last;    
    }

    vector<pair<int, const char*>> ans; 
    ans.reserve(pos.size());
    for (const auto&p : pos) {
        ans.emplace_back(p.second, p.first.c_str());
    }
    sort(ans.begin(), ans.end());
    for (const auto&p : ans) {
        printf("%s\n", p.second);
    }

    return 0;
}