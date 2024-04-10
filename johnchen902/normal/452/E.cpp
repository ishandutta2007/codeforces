#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <stack>
using namespace std;

char str[300003];
int lenstr;
int sa[300002];
int pos[300002];
int tmp[300002];

struct Cmp {
    const int gap;
    Cmp(int g): gap(g) {}
    bool operator()(int a, int b) const {
        if(pos[a] != pos[b])
            return pos[a] < pos[b];
        a += gap;
        b += gap;
        return (a < lenstr && b < lenstr) ? pos[a] < pos[b] : a > b;
    }
};

void build_sa() {
    iota(sa, sa + lenstr, 0);
    copy_n(str, lenstr, pos);
    for(int gap = 1; ; gap <<= 1) {
        sort(sa, sa + lenstr, Cmp(gap));
        for(int i = 0; i < lenstr - 1; i++)
            tmp[i + 1] = tmp[i] + Cmp(gap)(sa[i], sa[i + 1]);
        for(int i = 0; i < lenstr; i++)
            pos[sa[i]] = tmp[i];
        if(tmp[lenstr - 1] == lenstr - 1)
            break;
    }
}

int lcp[300002];

void build_lcp() {
    for(int i = 0, k = 0; i < lenstr; i++)
        if(pos[i] != lenstr - 1) {
            for(int j = sa[pos[i] + 1]; str[i + k] == str[j + k]; k++)
                ;
            lcp[i] = k;
            if(k)
                k--;
        }
}

int len1, len2, len3;

void read_input() {
    char *s1 = str;
    scanf("%s", s1);
    len1 = strlen(s1);
    s1[len1] = '$';

    char *s2 = s1 + len1 + 1;
    scanf("%s", s2);
    len2 = strlen(s2);
    s2[len2] = '%';

    char *s3 = s2 + len2 + 1;
    scanf("%s", s3);
    len3 = strlen(s3);
    lenstr = len1 + 1 + len2 + 1 + len3;
}

using T = tuple<int, int, int, int>;

void increase(int i, T& t, int delta = 1) {
    if(i < len1)
        get<1>(t) += delta;
    else if(i < len1 + 1 + len2)
        get<2>(t) += delta;
    else
        get<3>(t) += delta;
}

constexpr int mod = 1000000007;

int bit[1 << 19];

void adjust(int& i) {
    if(i >= mod) i -= mod;
    if(i < 0) i += mod;
}

void modify(int x, int v) {
    x++;
    while(x <= (1 << 19)) {
        adjust(bit[x - 1] += v);
        x += x & -x;
    }
}

int query(int x) {
    int v = 0;
    x++;
    while(x) {
        adjust(v += bit[x - 1]);
        x -= x & -x;
    }
    return v;
}

int main(){
    read_input();
    build_sa();
    build_lcp();

    stack<T> st;
    st.push(T(0, 0, 0, 0));
    for(int i = 2; i <= lenstr; i++) {
        while(get<0>(st.top()) > lcp[sa[i]]) {
            T t = st.top();
            st.pop();
            if(get<0>(st.top()) < lcp[sa[i]]) {
                st.push(T(lcp[sa[i]], get<1>(t), get<2>(t), get<3>(t)));
            } else {
                get<1>(st.top()) += get<1>(t);
                get<2>(st.top()) += get<2>(t);
                get<3>(st.top()) += get<3>(t);
            }
            int delta = (long long) get<1>(t) * get<2>(t) * get<3>(t) % mod;
            modify(get<0>(st.top()) + 1, +delta);
            modify(get<0>(t)        + 1, -delta);
        }
        if(get<0>(st.top()) < lcp[sa[i]]) {
            increase(sa[i], st.top(), -1);
            st.push(T(lcp[sa[i]], 0, 0, 0));
            increase(sa[i], st.top());
        }
        increase(sa[i + 1], st.top());
    }

    for(int i = 1; i <= min(len1, min(len2, len3)); i++)
        printf("%d%c", query(i), i == min(len1, min(len2, len3)) ? '\n' : ' ');
}