#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

const int MAX_VALUES = (2e5 + 1);
const int MOD = (998244353);

struct fenwick_tree {
    vector <int> Fenwick;
    int size = 0, log_max = 0;
    
    // remember to call this at the start !
    void set_to_size(int n) {
        Fenwick.resize(n);
        size = n;
        log_max = 31 - __builtin_clz(n);
        return;
    }
    
    // destroys everything : ready to be used again !
    void clear() {
        Fenwick.clear();
        size = log_max = 0;
        return;
    }
    
    // turns an array A of size n into a BIT : equivalent to adding each element, but faster
    // void build(vector <int> &Array, int n = -1) {  // you may use this instead
    void build(int* Array, int n = -1) {
        if (n < 0)
            n = size;
        for (int i = 0; i < size; i ++)
        {
            if (i < n)
                Fenwick[i] += Array[i];
            if ((i | (i + 1)) < size)
                Fenwick[i | (i + 1)] += Fenwick[i];
        }
        return;
    }
    
    // adds value to index-th element (zero-based)
    void add(int index, int value) {
        for (; index < size; index |= (index + 1))
            Fenwick[index] += value;
        return;
    }
    
    // returns sum over [0, right[
    int pref_sum(int right) {
        int ans = 0;
        for (; right; right &= (right - 1))
            ans += Fenwick[right - 1];
        return ans;
    }
    
    // returns sum over [left, right[ : equivalent to pref_sum(right) - pref_sum(left), but faster
    int range_sum(int left, int right) {
        int ans = 0;
        for (; right > left; right &= (right - 1))
            ans += Fenwick[right - 1];
        for (; left > right; left &= (left - 1))
            ans -= Fenwick[left - 1];
        return ans;
    }
    
    // returns the value of the index-th element
    int get(int index) {
        return range_sum(index, index + 1);
    }
    
    // set the index-th element to value
    void set(int index, int value) {
        add(index, value - get(index));
        return;
    }
    
    // returns the largest index i such that pref_sum(i) < value
    // requires that all values are non-negative !
    int last_under(int value) {
        int ans = -1;
        for (int bit = (1 << log_max); bit; bit >>= 1)
        {
            if (ans + bit < size && Fenwick[ans + bit] < value)
                value -= Fenwick[ans += bit];
        }
        return ++ ans;
    }
    
    // returns the smallest index i such that pref_sum(i) >= value
    // requires that all values are non-negative !
    int first_over(int value) {
        return last_under(value) + 1;
    }
};

fenwick_tree Fenw;

int Fact[MAX_VALUES];
int InvFact[MAX_VALUES];

int Occ[MAX_VALUES];

int Dep[MAX_VALUES];
int Fin[MAX_VALUES];

int szDep, szFin;

int fast_expo(int a, int n = MOD - 2) {
    int ans = 1, cur = a;
    for (; n; n >>= 1, cur = (cur * cur) % MOD)
        if (n & 1)
            ans = (ans * cur) % MOD;
    return ans;
}

void Solve() {
    scanf("%lld %lld", &szDep, &szFin);
    Fenw.set_to_size(MAX_VALUES);
    Fact[0] = 1;
    for (int i = 0; i < szDep; i ++)
    {
        scanf("%lld", &Dep[i]);
        Occ[Dep[i]] ++;
        Fenw.add(Dep[i], 1);
        Fact[i + 1] = (Fact[i] * (i + 1)) % MOD;
    }
    InvFact[szDep] = fast_expo(Fact[szDep]);
    for (int i = szDep - 1; i >= 0; i --)
    {
        InvFact[i] = (InvFact[i + 1] * (i + 1)) % MOD;
    }
    for (int i = 0; i < szFin; i ++)
    {
        scanf("%lld", &Fin[i]);
    }
    Fin[szFin ++] = 0;
    int nbStringsLeft = Fact[szDep];
    for (int i = 1; i < MAX_VALUES; i ++)
    {
        if (Occ[i])
        {
            nbStringsLeft *= InvFact[Occ[i]];
            nbStringsLeft %= MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i <= szDep; i ++)
    {
        if (i == szDep && i < szFin - 1)
            ans ++;
        nbStringsLeft *= fast_expo(szDep - i);
        nbStringsLeft %= MOD;
        int cur = Fenw.pref_sum(Fin[i]) * nbStringsLeft;
        ans += cur % MOD;
        if (Occ[Fin[i]])
        {
            nbStringsLeft *= Fact[Occ[Fin[i]]];
            nbStringsLeft %= MOD;
            Fenw.add(Fin[i], -1);
            Occ[Fin[i]] --;
            nbStringsLeft *= InvFact[Occ[Fin[i]]];
            nbStringsLeft %= MOD;
        }
        else
            break;
    }
    printf("%lld\n", ans % MOD);
    return;
}

signed main() {
    int nbTests = 1;
    // scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}