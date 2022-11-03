#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;

//  <|_|>

//  Right on time

const int MAX_VALUES = (2e5);

struct node {
    int nb_left, nb_right;
    int val_left, val_right;
    int sum;
    int size;
};

template <class T = int, class F = int>
struct segment_tree {
    vector <T> Tree;
    vector <F> Flags;
    int size = 0, log_max = 0;
    
    // =================== TO FILL ====================
    
    // put here your favorite operation on nodes like min, max, gcd ...
    inline T combine(T left_value, T right_value) {
        node ans;
        ans.size = left_value.size + right_value.size;
        ans.nb_left = left_value.nb_left;
        if (left_value.size == left_value.nb_left && left_value.val_right <= right_value.val_left)
            ans.nb_left += right_value.nb_left;
        ans.nb_right = right_value.nb_right;
        if (right_value.size == right_value.nb_right && right_value.val_left >= left_value.val_right)
            ans.nb_right += left_value.nb_right;
        ans.val_left = left_value.val_left;
        ans.val_right = right_value.val_right;
        ans.sum = left_value.sum + right_value.sum;
        if (left_value.size > left_value.nb_left)
        {
            if (ans.nb_right == right_value.size)
                ans.sum += (left_value.nb_right + 1) * left_value.nb_right;
            if (right_value.nb_right < right_value.size)
            {
                if (left_value.val_right <= right_value.val_left)
                    ans.sum += (left_value.nb_right + right_value.nb_left + 1) * (left_value.nb_right + right_value.nb_left);
                else
                {
                    ans.sum += (left_value.nb_right + 1) * left_value.nb_right;
                    ans.sum += (right_value.nb_left + 1) * right_value.nb_left;
                }
            }
        }
        if (right_value.size > right_value.nb_right)
            if (ans.nb_left == left_value.size)
                ans.sum += (right_value.nb_left + 1) * right_value.nb_left;
        return ans;
    }
    
    bool using_lazy = false;  // set to true if you want to enable lazy flags
    
    // put here your favorite operation on flags
    inline F combine_flags(F old_flag, F new_flag) {
        return old_flag + new_flag;
    }
    
    bool flags_commute = false;  // set to true if combine_flags is commutative (speeds up a little)
    
    // put here how values and flags interact
    inline T combine_with_flag(T value, F flag) {
        flag ++;
        return value;
    }
    
    T start_value = {0, 0, 1 << 30, 0, 0, 0};  // put here the default value of a node
    T null_value = start_value;  // put here the identity value of combine
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

segment_tree <node> Segt;

int nbValues, nbQueries;

void Solve() {
    scanf("%lld %lld", &nbValues, &nbQueries);
    Segt.set_to_size(nbValues);
    for (int i = 0; i < nbValues; i ++)
    {
        int a;
        scanf("%lld", &a);
        Segt.set(i, {1, 1, a, a, 0, 1});
    }
    for (int i = 0; i < nbQueries; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1)
            Segt.set(-- b, {1, 1, c, c, 0, 1});
        else
        {
            node ans = Segt.range_op(-- b, c);
            // printf("%lld %lld %lld %lld %lld %lld\n", ans.nb_left, ans.nb_right, ans.val_left, ans.val_right, ans.sum, ans.size);
            if (ans.nb_left == ans.size)
                printf("%lld\n", ((ans.size + 1) * (ans.size)) / 2);
            else
            {
                ans.sum += (ans.nb_left + 1) * ans.nb_left;
                ans.sum += (ans.nb_right + 1) * ans.nb_right;
                printf("%lld\n", ans.sum / 2);
            }
        }
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