#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  It that's what it takes to save the world, it's better to let that world die

const int MAX_CASES = (4e5);
const int MOD = (998244353);

pair <int, int> Inserts[MAX_CASES];
pair <int, int> Id[MAX_CASES];

int Plus[MAX_CASES];

struct ordered_multiset {  // only works with non-negative integers
    vector <int> Fenwick;  // to use if values are small
    // map <int, int> Fenwick;  // to use if values can be large
    // unordered_map <int, int> Fenwick;  // or this
    int size = 0, log_max = 0;  // all elements should be in the range [0, size[ !
    
    // remember to call this at the start !
    void set_to_size(int n) {
        Fenwick.resize(n);  // disable this line when using map
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
    
    // classics BIT operations (zero-based)
    void add(int index, int value) {
        for (; index < size; index |= (index + 1))
            Fenwick[index] += value;
        return;
    }
    
    int pref_sum(int right) {
        int ans = 0;
        for (; right > 0; right &= (right - 1))
            ans += Fenwick[right - 1];
        return ans;
    }
    
    int range_sum(int left, int right) {
        int ans = 0;
        for (; right > left; right &= (right - 1))
            ans += Fenwick[right - 1];
        for (; left > right; left &= (left - 1))
            ans -= Fenwick[left - 1];
        return ans;
    }
    
    // returns the number of elements value present in the set
    int count(int value) {
        return range_sum(value, value + 1);
    }
    
    // inserts nb times an element value
    void insert(int value, int cnt = 1) {
        add(value, cnt);
        return;
    }
    
    // erases nb times an element value
    void erase(int value, int cnt = 1) {
        cnt = min(cnt, count(value));
        add(value, - cnt);
        return;
    }
    
    // returns the position of element value in the set (zero-based)
    int order_of_key(int value) {
        return pref_sum(value);
    }
    
    // returns the element of position pos in the set (zero-based) : will return size if there are not enough elements in the set
    int find_by_order(int pos) {
        pos ++;
        int ans = -1;
        for (int bit = (1 << log_max); bit > 0; bit >>= 1)
        {
            if (ans + bit < size && Fenwick[ans + bit] < pos)
            {
                ans += bit;
                pos -= Fenwick[ans];
            }
        }
        return ++ ans;
    }
    
    // returns the first element >= value in the set, or size if there is no such element
    int lower_bound(int value) {
        return find_by_order(pref_sum(value));
    }
    
    // returns the first element > value in the set, or size if there is no such element
    int upper_bound(int value) {
        return find_by_order(pref_sum(value + 1));
    }
    
    // returns the last element < value in the set, or 0 if there is no such element
    int less_bound(int value) {
        return find_by_order(pref_sum(value) - 1);
    }
    
    // since there are no iterators, you can use less_bound and upper_bound to move from an element to the previous or to the next
    
    // returns the positions left, right such that elements of the set in the range [left, right[ are exactly those equal to value
    pair <int, int> equal_range(int value) {
        return make_pair(lower_bound(value), upper_bound(value));
    }
    
    // returns the number of elements in the set
    int get_size() {
        return pref_sum(size);
    }
    
    // checks if the set is empty
    bool empty() {
        return pref_sum(size) == 0;
    }
};

int Fact[MAX_CASES];
int InvFact[MAX_CASES];

ordered_multiset Free;

int nbCases, nbInsert;

int fast_expo(int a, int n) {
    int ans = 1, cur = a;
    for (; n > 0; n >>= 1, cur = (cur * cur) % MOD)
        if (n & 1)
            ans = (ans * cur) % MOD;
    return ans;
}

void Init() {
    Fact[0] = 1;
    for (int i = 1; i < MAX_CASES; i ++)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
    }
    InvFact[MAX_CASES - 1] = fast_expo(Fact[MAX_CASES - 1], MOD - 2);
    for (int i = MAX_CASES - 1; i > 0; i --)
    {
        InvFact[i - 1] = (InvFact[i] * i) % MOD;
    }
    Free.set_to_size(MAX_CASES);
    for (int i = 0; i < MAX_CASES; i ++)
    {
        Free.insert(i);
    }
    return;
}

int Choose(int k, int n) {
    return (Fact[n] * ((InvFact[k] * InvFact[n - k]) % MOD)) % MOD;
}

void Solve() {
    scanf("%lld %lld", &nbCases, &nbInsert);
    int nb = nbCases - 1 - nbInsert;
    for (int i = 0; i < nbInsert; i ++)
    {
        scanf("%lld %lld", &Inserts[i].first, &Inserts[i].second);
    }
    for (int i = nbInsert - 1; i >= 0; i --)
    {
        int a = Free.find_by_order(-- Inserts[i].second);
        int b = Free.upper_bound(a);
        nb += Plus[b] ++ > 0;
        Free.erase(a);
        Id[i] = {a, b};
    }
    printf("%lld\n", Choose(nb, nb + nbCases));
    for (int i = 0; i < nbInsert; i ++)
    {
        Free.insert(Id[i].first);
        Plus[Id[i].second] --;
    }
    return;
}

signed main() {
    Init();
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Solve();
    }
    return 0;
}