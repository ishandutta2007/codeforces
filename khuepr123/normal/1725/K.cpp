#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 4e5 + 5;

int n;
int a[N];
int q;

struct interval_t;
set <interval_t>::iterator pa[N];

struct interval_t{
    mutable int val;
    mutable set <int> stta;

    interval_t(){

    }

    interval_t(int val): val(val){

    }

    interval_t(int val, int i): val(val){
        stta.emplace(i);
    }

    // friend void sswap(interval_t &lhs, interval_t &rhs){
    //     swap(lhs.val, rhs.val);
    //     swap(lhs.stta, rhs.stta);
    // }

    friend void merge(set <interval_t>::iterator plhs, set <interval_t>::iterator prhs){ // merge into lhs
        // if (isz(lhs.stta) < isz(rhs.stta)){
        //     swap(lhs, rhs);
        // }
        Fora(i, prhs->stta){
            plhs->stta.emplace(i);
            pa[i] = plhs;
        }
        return;
    }

    friend bool operator< (const interval_t &lhs, const interval_t &rhs){
        return lhs.val < rhs.val;
    }

    friend ostream& operator<< (ostream& out, const interval_t &rhs){
        out << '{' << rhs.val << ", {";
        Fora(i, rhs.stta){
            out << i;
            if (i != *prev(rhs.stta.end())){
                out << ", ";
            }
        } out << "}}";
        return out;
    }
};

set <interval_t> stt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        auto itr = stt.find(interval_t(a[i]));
        if (itr != stt.end()){
            itr->stta.emplace(i);
            pa[i] = itr;
        }
        else{
            pa[i] = stt.emplace(a[i], i).fi;
        }
    }

    cin >> q; while (q--){
        int type; cin >> type;
        if (type == 1){
            int i, val; cin >> i >> val;
            auto itr = pa[i];
            itr->stta.erase(i);
            if (itr->stta.empty()){
                stt.erase(itr);
            }
            a[i] = val;
            itr = stt.find(interval_t(a[i]));
            if (itr != stt.end()){
                itr->stta.emplace(i);
                pa[i] = itr;
            }
            else{
                pa[i] = stt.emplace(a[i], i).fi;
            }
        }
        else if (type == 2){
            int i; cin >> i;
            cout << pa[i]->val << endl;
        }
        else{
            int l, r; cin >> l >> r;
            int m = (l + r) >> 1;
            auto set_range = [&](int l, int r, int val){
                set <interval_t>::iterator pprev = stt.end();
                auto itr = stt.lower_bound(interval_t(l));
                while (itr != stt.end() and itr->val <= r){
                    if (pprev == stt.end()){
                        pprev = itr;
                        itr++;
                        continue;
                    }
                    if (isz(pprev->stta) < isz(itr->stta)){
                        swap(pprev, itr);
                    }
                    merge(pprev, itr);
                    stt.erase(itr);
                    itr = next(pprev);
                }
                if (pprev != stt.end()){
                    pprev->val = val;
                }
                return;
            };
            set_range(l - 1, m, l - 1);
            set_range(m + 1, r + 1, r + 1);
        }
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/