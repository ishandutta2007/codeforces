#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;

vector<string> licz(const vector<string>& v) {
    set<string> secik;
    for (auto s : v) {
        bool is_ok = true;
        for(auto t : v) {
                if (t.size() > s.size()) {
                    if (t.substr(t.size() - s.size()) == s) {
                        is_ok = false;
                        break;
                    }
                }
        }
        if (is_ok) secik.IN(s);
    }
    return vector<string>(ALL(secik));
}

void jebaj() {
    int n;
    cin >> n;
    map<string, vector<string>> mapka;
    REP(i, n) {
        string name;
        cin >> name;
        int ile;
        cin >> ile;
        REP(_, ile) {
            string nr;
            cin >> nr;
            mapka[name].push_back(nr);
        }
    }
    cout << mapka.size() << "\n";
    for(const auto& p : mapka) {
        cout  << p.first << " ";
        auto numerki = licz(p.second);
        cout << numerki.size() << " ";
        for (auto nn : numerki) cout << nn << " "; cout << "\n";
    }
}
#undef int
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}