#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct pizza {
    int index;
    int price;
    int ingredient;
    pizza(int a, int b, int c) {
        index = a;
        price = b;
        ingredient = c;
    }
};

bool operator< (pizza a, pizza b) {
    return a.price < b.price;
}

vector<pizza> PRICE[1000];
int people[1000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int now = 0;
        int num;
        cin >> num;
        while(num--) {
            int in;
            cin >> in;
            in--;
            now |= (1 << in);
        }
        people[now]++;
    }
    for(int i = 1; i <= M; i++) {
        pizza now(i, 0, 0);
        cin >> now.price;
        int num;
        cin >> num;
        while(num--) {
            int in;
            cin >> in;
            in--;
            now.ingredient |= (1 << in);
        }
        PRICE[now.ingredient].push_back(now);
    }
    for(int i = 0; i < (1 << 9); i++) {
        sort(PRICE[i].begin(), PRICE[i].end());
    }
    i_i ans;
    ans.first = 0;
    ans.second = 1;
    int anspeople = 0;
    int ansprice = INF + 1;
    for(int a = 0; a < (1 << 9); a++) {
        if(PRICE[a].empty()) continue;
        for(int b = a; b < (1 << 9); b++) {
            if(PRICE[b].empty()) continue;
            //cerr << a << " " << b << " " << anspeople << " "<< ansprice << endl;
            //cerr << PRICE[a].size() << endl;
            int nowgredient = a | b;
            int nowpeople = 0;
            for(int person = 0; person < (1 << 9); person++) {
                if((person & nowgredient) == person) {
                    nowpeople += people[person];
                }
            }
            if(a != b) {
                if(nowpeople > anspeople || (nowpeople == anspeople && PRICE[a][0].price + PRICE[b][0].price < ansprice)) {
                    ans.first = PRICE[a][0].index;
                    ans.second = PRICE[b][0].index;
                    anspeople = nowpeople;
                    ansprice = PRICE[a][0].price + PRICE[b][0].price;
                }
            } else {
                if(PRICE[a].size() >= 2) {
                    //cerr << "AAA" << endl;
                    if(nowpeople > anspeople || (nowpeople == anspeople && PRICE[a][0].price + PRICE[a][1].price < ansprice)) {
                    ans.first = PRICE[a][0].index;
                    ans.second = PRICE[a][1].index;
                    anspeople = nowpeople;
                    ansprice = PRICE[a][0].price + PRICE[a][1].price;
                    }
                }
            }
        }
    }
    cout << ans.first << " "<< ans.second << endl;
    return 0;
}