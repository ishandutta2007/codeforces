#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  M. Broccoli

const int MAX_VALUES = (2e5 + 1);

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

char Brackets[MAX_VALUES];
int Height[MAX_VALUES];

pair <int, int> Values[MAX_VALUES];

fenwick_tree Count;
fenwick_tree Sums;

pair <int, int> Stack[MAX_VALUES];
int fin = 0;

int Left[MAX_VALUES];
int Right[MAX_VALUES];

int nbValues;

void Read() {
    scanf("%lld %s", &nbValues, Brackets);
    nbValues ++;
    Height[0] = 0;
    Values[0] = {0, 0};
    for (int i = 1; i < nbValues; i ++)
    {
        Height[i] = Height[i - 1] + (Brackets[i - 1] == '(' ? 1 : -1);
        Values[i] = {Height[i], i};
    }
    sort(Values, Values + nbValues);
    Count.clear();
    Sums.clear();
    Count.set_to_size(nbValues);
    Sums.set_to_size(nbValues);
    int ans = 0;
    for (int i = 0; i < nbValues; i ++)
    {
        ans -= Sums.pref_sum(Values[i].second);
        ans += Values[i].first * Count.pref_sum(Values[i].second);
        Sums.add(Values[i].second, Values[i].first);
        Count.add(Values[i].second, 1);
    }

    fin = 0;
    Stack[fin ++] = {- MAX_VALUES, -1};
    for (int i = 0; i < nbValues; i ++)
    {
        while (fin && Stack[fin - 1].first > Height[i])
            fin --;
        Left[i] = Stack[fin - 1].second;
        Stack[fin ++] = {Height[i], i};
    }
    fin = 0;
    Stack[fin ++] = {- MAX_VALUES, nbValues};
    for (int i = nbValues - 1; i >= 0; i --)
    {
        while (fin && Stack[fin - 1].first >= Height[i])
            fin --;
        Right[i] = Stack[fin - 1].second;
        Stack[fin ++] = {Height[i], i};
    }
    
    for (int i = 1; i < nbValues; i ++)
    {
        int a = Sums.range_sum(Left[i] + 1, i) - Height[i] * (i - Left[i] - 1);
        ans += a * (Right[i] - i);
    }
    
    printf("%lld\n", ans);
    return;
}

signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
    {
        Read();
    }
    return 0;
}