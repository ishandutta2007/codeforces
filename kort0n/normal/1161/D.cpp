#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;
string S;

ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b % 2 == 1) ret = ret * a % mod;
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    ll blen = S.size();
    reverse(S.begin(), S.end());
    S = "#" + S;
    ll ans = 0;
    for(ll alen = blen - 1; alen >= 1; alen--) {
        //cerr << alen << endl;
        ll nowval = 1;
        queue<i_i> oneque, zeroque, freeque;
        set<i_i> one, zero, free;
        for(int i = 1; i <= alen; i++) {
            free.insert({i, 1});
        }
        for(int i = 1; i <= blen; i++) {
            free.insert({i, 0});
        }
        //cerr << S << endl;
        //cerr << alen << " " << blen << endl;
        for(int i = alen + 1; i <= blen; i++) {
            if(S[i] == '0') zeroque.push({i, 0});
            if(S[i] == '1') oneque.push({i, 0});
        }
        oneque.push({alen, 1});
        while(!oneque.empty() || !zeroque.empty()) {
            //cerr << "A" << endl;
            if(!oneque.empty()) {
                i_i now = oneque.front();
                oneque.pop();
                one.insert(now);
                if(zero.find(now) != zero.end()) nowval = 0;
                if(free.find(now) == free.end()) continue;
                //cerr << "ONE: " << now.first << " " << now.second << endl;
                free.erase(now);
                i_i search = now;
                if(now.second == 0) search.first = blen + 1 - now.first;
                else search.first = alen + 1 - now.first;
                if(free.find(search) != free.end()) {
                    oneque.push(search);
                } else {
                    if(zero.find(search) != zero.end()) nowval = 0;
                }
                search = now;
                search.second ^= 1;
                if(search.second == 1 && search.first > alen) continue;
                if(S[search.first] == '?') continue;
                if(free.find(search) != free.end()) {
                    if(S[search.first] == '1') zeroque.push(search);
                    else oneque.push(search);
                    continue;
                }
                if(one.find(search) != one.end() && S[search.first] == '1') nowval = 0;
                if(zero.find(search) != zero.end() && S[search.first] == '0') nowval = 0;
            }
            if(!zeroque.empty()) {
                i_i now = zeroque.front();
                zeroque.pop();
                zero.insert(now);
                if(one.find(now) != one.end()) nowval = 0;
                if(free.find(now) == free.end()) continue;
                //cerr << "ZERO: " << now.first << " " << now.second << endl;
                free.erase(now);
                i_i search = now;
                if(now.second == 0) search.first = blen + 1 - now.first;
                else search.first = alen + 1 - now.first;
                if(free.find(search) != free.end()) {
                    zeroque.push(search);
                } else {
                    if(one.find(search) != one.end()) nowval = 0;
                }
                search = now;
                search.second ^= 1;
                if(search.second == 1 && search.first > alen) continue;
                if(S[search.first] == '?') continue;
                if(free.find(search) != free.end()) {
                    if(S[search.first] == '1') oneque.push(search);
                    else zeroque.push(search);
                    continue;
                }
                if(one.find(search) != one.end() && S[search.first] == '0') nowval = 0;
                if(zero.find(search) != zero.end() && S[search.first] == '1') nowval = 0;
            }
        }
        bool allzero = true;
        bool existone = false;
        for(int i = 1; i <= alen; i++) {
            if(one.find({i, 1}) != one.end()) existone = true;
            if(zero.find({i, 1}) == zero.end()) allzero = false;
        }
        
        if(allzero) {
            nowval = 0;
            cerr << "ALLZERO" << endl;
        }
        if(!existone) {
            nowval = nowval * beki(2, mod - 2) % mod;
            cerr << "DONT EXIST ONE" << endl;
        }
        //if(all) nowval = nowval * beki(2, mod - 2) % mod;
        while(!free.empty()) {
            //cerr << "double" << endl;
            nowval = nowval * 2 % mod;
            auto itr = free.begin();
            freeque.push(*itr);
            //free.erase(itr);
            while(!freeque.empty()) {
                i_i now = freeque.front();
                freeque.pop();
                //cerr << "FREE: " << now.first << " " << now.second << endl;
                if(free.find(now) == free.end()) continue;
                free.erase(now);
                i_i search = now;
                if(now.second == 0) search.first = blen + 1 - now.first;
                else search.first = alen + 1 - now.first;
                if(free.find(search) != free.end()) {
                    freeque.push(search);
                }
                search = now;
                search.second ^= 1;
                if(search.second == 1 && search.first > alen) continue;
                if(S[search.first] == '?') continue;
                freeque.push(search);
            }
        }
        ans = (ans + nowval) % mod;
        cerr << alen << " " << nowval << endl;
    }
    cout << ans << endl;
    return 0;
}