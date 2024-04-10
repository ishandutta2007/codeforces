#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 1005;

int n;
int t[N];
vector<int> rozlozone[N];
const vector<int> pierwsze = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57 };

void rozloz (int a, int id) {
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            rozlozone[id].pb(i);
            while (a % i == 0) 
                a /= i;
        }
    }
    if (a != 1) 
        rozlozone[id].pb(a);
}

int znajdz (int a, int b) {
    set<pair<int, bool>> wspolne;
    for (int e : rozlozone[a])
        wspolne.insert({ e, 0 });
    for (int e : rozlozone[b])
        wspolne.insert({ e, 0 });
    for (int e : pierwsze)
        wspolne.insert({ e, 1 });

    int poprz = -1;
    for (auto e : wspolne) {
        if (e.second == 1 and poprz != e.first)
            return e.first;
        poprz = e.first;
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        rozloz(t[i], i);
    }

    int added = 0;
    vector<int> ans = { t[0] };
    for (int i = 1; i < n; i++) {
        if (gcd(t[i-1], t[i]) != 1) {
            ans.pb(znajdz(i-1, i));
            added++;
        }
        ans.pb(t[i]);
    }

    printf("%d\n", added);
    for (int e : ans)
        printf("%d ", e);
    return 0;
}