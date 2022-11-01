#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

struct node {
    int key, prior;
    int cnt;
    ll add;
    ll sum;
    int sz;
    node *l, *r;
    node () {}
    node ( int _k ) {
        sz = 1;
        cnt = 1;
        key = _k;
        sum = _k;
        add = 0;
        prior = ( rand() << 16 ) + rand();
        l = r = NULL;
    }
};

typedef node * pnode;

inline ll GetSum(pnode T) {
    return T ? T -> sum : 0;
}

inline int GetSz(pnode T) {
    return T ? T -> sz : 0;
}

inline void push(pnode T) {
    if (T -> l) {
        T -> l -> add += T -> add;
        T -> l -> sum += 1LL * T -> add * T -> l -> sz;
        T -> l -> key += T -> add;
    }
    if (T -> r) {
        T -> r -> add += T -> add;
        T -> r -> sum += 1LL * T -> add * T -> r -> sz;
        T -> r -> key += T -> add;
    }
    T -> add = 0;
}

inline void merge ( pnode &T, pnode L, pnode R ) {
    if ( !L ) {
        T = R;
        return;
    }
    if ( !R ) {
        T = L;
        return;
    }
    push(L);
    push(R);
    if ( L -> prior > R -> prior ) {
        merge( L -> r, L -> r, R );
        T = L;
        T -> sum = GetSum(T -> l) + GetSum(T -> r) + 1LL * T -> key * T -> cnt;
        T -> sz = GetSz(T -> l) + GetSz(T -> r) + T -> cnt;
        return;
    }
    merge( R -> l, L, R -> l );
    T = R;
    T -> sum = GetSum(T -> l) + GetSum(T -> r) + 1LL * T -> key * T -> cnt;
    T -> sz = GetSz(T -> l) + GetSz(T -> r) + T -> cnt;     
}

inline void split ( pnode T, int x, pnode &L, pnode &R ) {
    if ( !T ) {
        L = R = NULL;
        return;
    }
    push(T);
    if ( T -> key > x ) {
        split( T -> l, x, L, T -> l );
        T -> sum = GetSum(T -> l) + GetSum(T -> r) + 1LL * T -> key * T -> cnt;
        T -> sz = GetSz(T -> l) + GetSz(T -> r) + T -> cnt;
        R = T;
        return;
    }
    split( T -> r, x, T -> r, R );
    T -> sum = GetSum(T -> l) + GetSum(T -> r) + 1LL * T -> key * T -> cnt;
    T -> sz = GetSz(T -> l) + GetSz(T -> r) + T -> cnt;
    L = T;
}

inline bool Find(pnode T, int x) {
    if (!T)
        return 0;
    push(T);
    if (T -> key == x) {
        ++T -> cnt;
        ++T -> sz;
        T -> sum += 1LL * T -> key;
        return 1;
    }
    bool was = false;
    if (T -> key > x) {
        was = Find(T -> l, x);
    } else
        was = Find(T -> r, x);
    T -> sum = GetSum(T -> l) + GetSum(T -> r) + 1LL * T -> key * T -> cnt;
    T -> sz = GetSz(T -> l) + GetSz(T -> r) + T -> cnt;
    return was;
}

int a[maxn];
int b[maxn];

pnode T = NULL;
pnode L = NULL;
pnode R = NULL;

inline void Add(pnode& T, pnode x) {
    if ( !T ) {
        T = x;
        return;
    }
    if (Find(T, x -> key))
        return;
    split( T, x -> key, L, R );
    merge( T, L, x );
    merge( T, T, R );
} 

void out ( pnode T ) {
    if ( !T ) return;
    push(T);
    out( T -> l );
    printf ( "%d ", T -> key );
    out( T -> r );
}

inline ll Update(pnode& T, int x) {
    split(T, -x, L, R);
    ll ans = GetSum(L);
    T = R;
    if (!T)
        return ans;
    ans += 1LL * GetSz(T) * -x;
    T -> add += 1LL * x;
    T -> sum += 1LL * x * GetSz(T);
    T -> key += 1LL * x;
    return ans;
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &b[i]);
    for (int i = 0; i < n; ++i) {
        Add(T, new node(a[i]));
        // cout << endl;
        ll ans = Update(T, -b[i]);
        printf("%I64d\n", ans);
        // out(T);
    }
    return 0;
}