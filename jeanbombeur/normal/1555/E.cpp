#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Petit coup de chance

const int MAX_SEGMENTS = (300 * 1000);

template <class T = int, class F = int>
struct segtree {
    vector <T> Tree;
    int size = 0, logMax = 0;
    
    bool using_lazy = false;
    vector <F> Flags;
    
    // ============== TO FILL ===============
    
    // put here your favorite operation on nodes like min, max, gcd ... (doesn't need to be commutative)
    inline T combine(T left_value, T right_value) {
        return min(left_value, right_value);
    }
    
    // put here your favorite operation on flags
    inline F combine_flags(F old_flag, F new_flag) {
        return old_flag + new_flag;
    }
    
    // put here how values and flags interact
    inline T combine_with_flag(T value, F flag) {
        return value + flag;
    }
    
    T startValue = 0;  // put here the default value of a node
    T nullValue = (1 << 30);  // put here the identity value of combine
    F nullFlag = 0;  // put here the identity value of combine_flags
    
    // =======================================
    
    // remember to call this at the start !
    // n doesn't need to be a power of two
    void set_to_size(int n) {
        Tree.resize(2 * n, startValue);
        size = n;
        logMax = 32 - __builtin_clz(n);
        return;
    }
    
    // destroys everything : ready to be used again !
    void clear() {
        Tree.clear();
        Flags.clear();
        size = logMax = 0;
        return;
    }
    
    // call this if you want to enable lazy flags (to do just after set_to_size() !)
    // cannot be undone (but why would you ?)
    void use_lazy() {
        using_lazy = true;
        Flags.resize(size, nullFlag);
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
    
    // changes the index-th element to value
    void update(int index, T value) {
        Tree[index += size] = value;
        for (index >>= 1; index > 0; index >>= 1)
            Tree[index] = combine(Tree[index << 1], Tree[(index << 1) ^ 1]);
        return;
    }
    
    // combines value to the flag of node index
    void put_flag(int index, F flag) {
        Tree[index] = combine_with_flag(Tree[index], flag);
        if (index < size)
            Flags[index] = combine_flags(Flags[index], flag);
        return;
    }
    
    // pushes all flags above node index
    void push(int index) {
        for (int h = logMax; h > 0; h --)
        {
            int p = index >> h;
            if (Flags[p] != nullFlag)
            {
                put_flag(p << 1, Flags[p]);
                put_flag((p << 1) ^ 1, Flags[p]);
                Flags[p] = nullFlag;
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
    
    // combines lazily a flag to the range [left, right[
    void range_add(int left, int right, F flag) {
        left += size, right += size;
        // you can remove the next line if combine_flags is commutative
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
    
    // returns combine of all elements in range [left, right[
    T range_op(int left, int right) {
        left += size, right += size;
        if (using_lazy)
            push(left), push(right - 1);
        T left_ans = nullValue, right_ans = nullValue;
        for (; left < right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                left_ans = combine(left_ans, Tree[left ++]);
            if (right & 1)
                right_ans = combine(Tree[-- right], right_ans);
        }
        return combine(left_ans, right_ans);
    }
    
    // prints the tree rotated 45 degrees left
    void print(int a = 1, int p = 0) {
        if (a >= 2 * size)
            return;
        print((a << 1) ^ 1, p + 1);
        for (int i = 0; i < p; i ++)
            printf("\t");
        printf("%d\n", Tree[a]);  // you can print whatever you want
        print(a << 1, p + 1);
        return;
    }
};
 
segtree <> Segt;
 
pair <int, pair <int, int>> Segments[MAX_SEGMENTS];
 
int nbSegments, nbPoints;
 
void Read() {
    scanf("%lld %lld", &nbSegments, &nbPoints);
    for (int i = 0; i < nbSegments; i ++)
    {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        Segments[i] = {c, {-- a, -- b}};
    }
    Segt.set_to_size(nbPoints - 1);
    Segt.use_lazy();
    sort(Segments, Segments + nbSegments);
    
    int mini = (1LL << 60);
 
    int droite = 0;
 
    for (int i = 0; i < nbSegments; i ++)
    {
        while (droite < nbSegments && Segt.Tree[1] == 0)
        {
            Segt.range_add(Segments[droite].second.first, Segments[droite].second.second, 1);
            droite ++;
        }
        if (Segt.Tree[1] == 1)
            mini = min(mini, Segments[droite - 1].first - Segments[i].first);
        Segt.range_add(Segments[i].second.first, Segments[i].second.second, -1);
    }
    
    printf("%lld\n", mini);
    
    return;
}
 
signed main() {
    Read();
    return 0;
}