#include <bits/stdc++.h>
#define IOS std::cin.tie(nullptr)->sync_with_stdio(false);
using namespace std;

struct Orz {
    int id; 
    string str;
    bool operator<(const Orz& oth) const {
        return str < oth.str;
    }
};

int n, m;
vector<Orz> vec;

signed main() {
    IOS
    cin >> n >> m;
    for(int i = 1;i <= n;++i) {
        Orz orz;
        orz.id = i;
        cin >> orz.str;
        for(int j = 0;j < orz.str.size();++j) {
            if(j&1) {
                orz.str[j] = 'z' - orz.str[j] + 'a';
            }
        }
        vec.emplace_back(orz);
    }
    sort(vec.begin(), vec.end());
    for(const auto& orz : vec) {
        cout << orz.id << ' ';
    }
    cout << '\n';
    return 0;
}