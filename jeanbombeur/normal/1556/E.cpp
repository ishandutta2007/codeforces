#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

//  <|_|>

//  Hello there

const int MAX_VALUES = (2e5);

template <class T = int, class F = int>
struct segment_tree {
    vector <T> Tree;
    int size = 0, log_max = 0;
    
    vector <F> Flags;
    
    // =================== TO FILL ====================
    
    // put here your favorite operation on nodes like min, max, gcd ...
    inline T combine(T left_value, T right_value) {
        return {max(left_value.first, right_value.first), min(left_value.second, right_value.second)};
    }
    
    bool using_lazy = false;  // set to true if you want to enable lazy flags
    
    // put here your favorite operation on flags
    inline F combine_flags(F old_flag, F new_flag) {
        return old_flag + new_flag;
    }
    
    bool flags_commute = false;  // set to true if combine_flags is commutative (speeds up a little)
    
    // put here how values and flags interact
    inline T combine_with_flag(T value, F flag) {
        return {value.first + flag, value.second};
    }
    
    T start_value = {0, 0};  // put here the default value of a node
    T null_value = {- (1LL << 60), 1LL << 60};  // put here the identity value of combine
    F null_flag = 0;  // put here the default value of a flag
    
    // make sure that operator != is defined for flags !
    
    // ================= FOR DEBUG ====================
    
    // put here what you'd like to print about the nodes
    void print_value(T value) {
        printf("%d", value);
        return;
    }
    
    // put here what you'd like to print about the flags
    void print_flag(F flag) {
        printf("%d", flag);
        return;
    }
    
    // ======== DO NOT TOUCH AFTER THIS LINE ==========
    
    // remember to call this at the start !
    // n doesn't need to be a power of two
    void set_to_size(int n) {
        Tree.resize(2 * n, start_value);
        if (using_lazy)
            Flags.resize(n, null_flag);
        size = n;
        log_max = 32 - __builtin_clz(n);
        return;
    }
    
    // destroys everything : ready to be used again !
    void clear() {
        Tree.clear();
        Flags.clear();
        size = log_max = 0;
        return;
    }
    
    // turns an array of exactly size elements into a segtree : equivalent to updating each element but faster
    // void build(vector <T> &Array) {  // you may use this instead
    void build(T* Array) {
        for (int i = 0; i < size; i ++)
            Tree[i + size] = Array[i];
        for (int i = size - 1; i > 0; i --)
            Tree[i] = combine(Tree[i << 1], Tree[(i << 1) ^ 1]);
        return;
    }
    
    // combines flag to node index
    void put_flag(int index, F flag) {
        Tree[index] = combine_with_flag(Tree[index], flag);
        if (index < size)
            Flags[index] = combine_flags(Flags[index], flag);
        return;
    }
    
    // pushes all flags above node index
    void push(int index) {
        for (int h = log_max; h > 0; h --)
        {
            int p = index >> h;
            if (Flags[p] != null_flag)
            {
                put_flag(p << 1, Flags[p]);
                put_flag((p << 1) ^ 1, Flags[p]);
                Flags[p] = null_flag;
            }
        }
        return;
    }
    
    // updates all values above node index
    void pull(int index) {
        for (index >>= 1; index > 0; index >>= 1)
            Tree[index] = combine_with_flag(combine(Tree[index << 1], Tree[(index << 1) ^ 1]), Flags[index]);
        return;
    }
    
    // sets the index-th element to value (zero-based)
    void set(int index, T value) {
        index += size;
        if (using_lazy)
        {
            push(index);
            Tree[index] = value;
            pull(index);
            return;
        }
        Tree[index] = value;
        for (index >>= 1; index > 0; index >>= 1)
            Tree[index] = combine(Tree[index << 1], Tree[(index << 1) ^ 1]);
        return;
    }
    
    // returns the value of the index-th element (zero-based)
    T get(int index) {
        index += size;
        if (using_lazy)
            push(index);
        return Tree[index];
    }
    
    // combines lazily a flag to the range [left, right[  (zero-based)
    void range_add(int left, int right, F flag) {
        left += size, right += size;
        if (!flags_commute)
            push(left), push(right - 1);
        for (int l = left, r = right; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                put_flag(l ++, flag);
            if (r & 1)
                put_flag(-- r, flag);
        }
        pull(left), pull(right - 1);
        return;
    }
    
    // returns combine of all elements in range [left, right[  (zero-based)
    T range_op(int left, int right) {
        left += size, right += size;
        if (using_lazy)
            push(left), push(right - 1);
        T left_ans = null_value, right_ans = null_value;
        for (; left < right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                left_ans = combine(left_ans, Tree[left ++]);
            if (right & 1)
                right_ans = combine(Tree[-- right], right_ans);
        }
        return combine(left_ans, right_ans);
    }
    
    // prints the tree rotated 90 degrees left
    void print(int a = 1, int p = 0) {
        if (a >= 2 * size)
            return;
        if (a == 1)
        {
            for (int i = 0; i < 60; i ++)
                printf("=");
            printf("\n");
        }
        print((a << 1) ^ 1, p + 1);
        for (int i = 0; i < p; i ++)
            printf("\t");
        print_value(Tree[a]);
        if (using_lazy)
        {
            printf(" / ");
            if (a < size)
                print_flag(Flags[a]);
        }
        printf("\n");
        print(a << 1, p + 1);
        if (a == 1)
        {
            for (int i = 0; i < 60; i ++)
                printf("=");
            printf("\n");
        }
        return;
    }
};

int Val[MAX_VALUES];

segment_tree <pair <int, int>> Segt;

int nbValues, nbQueries;

void Solve() {
    scanf("%lld %lld", &nbValues, &nbQueries);
    nbValues ++;
    Segt.set_to_size(nbValues);
    for (int i = 0; i < 2; i ++)
    {
        int sum = 0;
        for (int j = 1; j < nbValues; j ++)
        {
            int a;
            scanf("%lld", &a);
            sum += a;
            Val[j] += sum * (i == 0 ? 1 : -1);
        }
    }
    for (int i = 1; i < nbValues; i ++)
    {
        Segt.set(i, {Val[i], Val[i]});
    }
    for (int i = 0; i < nbQueries; i ++)
    {
        int a, b;
        scanf("%lld %lld", &a, &b);
        int diff = Val[a - 1];
        pair <int, int> ans = Segt.range_op(a, b);
        if (Val[b] != diff || ans.first > diff)
            printf("-1\n");
        else
            printf("%lld\n", abs(ans.second - diff));
    }
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