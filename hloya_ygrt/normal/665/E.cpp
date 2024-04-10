#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e7 + 1, base = 1e8;
const int sigm = 26;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

struct smartTrie
{
    struct node
    {
        node * l, * r;
        int count;

        node():l(0), r(0){
            count = 0;
        }

        node * goLeft() {
            if (l == 0)
                l = new node();
            return l;
        }

        node * goRight() {
            if (r == 0)
                r = new node();
            return r;
        }
    };

    node * root;
    smartTrie() {
        root = new node();
    }

    int getCount(node * v) {
        if (v == NULL)
            return 0;
        return v->count;
    }

    void add(int& x) {
        node * ver = root;
        for (int i = 30; i >= 0; i--){
            if ((x & (1 << i)) == 0)
                ver = ver->goLeft();
            else
                ver = ver->goRight();
            ver->count++;
        }
    }

    int geq(int& x, int& k) {
        int answer = 0, added = 0;

        node * ver = root;
        node * dif, * notdif;

        for (int i = 30; i >= 0; i--){
            dif = ver->goLeft(), notdif = ver->goRight();

            if ((x & (1 << i)) == 0) {
                dif = ver->goRight(), notdif = ver->goLeft();
            }

            if (added + (1 << i) >= k) {
                answer += dif->count;
                ver = notdif;
            } else {
                added += (1 << i);
                ver = dif;
            }

            if (ver->count == 0)
                break;
        }

        return answer;
    }
};

int main() {
    smartTrie trie;

    int n, k;
    read(n, k);

    int prefixSum = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int x = input<int>();
        prefixSum ^= x;

        if (prefixSum >= k)
            ans++;
        ans += trie.geq(prefixSum, k);
        trie.add(prefixSum);
    }

    cout << ans;    
    return 0;
}