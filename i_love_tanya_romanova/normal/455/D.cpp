#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;

#define f(i,s,e) for (int i = int(s); i != int(e); i++)
#define ft(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(c) (c).begin(), (c).end()

//read scanf functions
#define readI(x) scanf("%d", &x)
#define readL(x) scanf("%I64d", &x)
#define readD(x) scanf("%f", &x)
#define readII(x, y) scanf("%d %d", &x, &y)
#define readLL(x, y) scanf("%I64d %I64d", &x, &y)

typedef long long ll; 

#define OO (1<<30)
#define MAX_N 100005
#define SQRT_N 320
int N, Q, SQ;
list<int> a[SQRT_N];
int cnt[SQRT_N][MAX_N];
void shiftRight(const int &l, const int &r) {
    if (l==r) return ;
    int fir = l/SQ, sec = r/SQ;
    list<int>::iterator last = a[sec].begin();
    list<int>::iterator begin = a[fir].begin();
    int cnt1 = fir*SQ;
    while (cnt1 != l) cnt1++, begin++;
    cnt1 = sec*SQ;
    while (cnt1 != r) cnt1++, last++;

    int item = (*last);
    a[sec].erase(last), cnt[sec][item]--;
    a[fir].insert(begin, (item));
    cnt[fir][item]++;

    for (int i=fir; i<sec; i++) {
        int nxt = i+1;
        item = *a[i].rbegin();
        cnt[i][item]--;
        a[i].pop_back();
        a[nxt].push_front(item);
        cnt[nxt][item]++;
    }
}

int calc(const int &l, const int &r, const int &val) {
    int ret = 0, fir = l/SQ, sec = r/SQ;
    list<int>::iterator last = a[sec].begin();
    list<int>::iterator begin = a[fir].begin();
    int cnt1 = fir*SQ, temp=0;
    while (cnt1 != l){
        if ((*begin)==val)ret--;
        cnt1++, begin++;
    }

    cnt1 = sec*SQ;
    while (cnt1 <= r){
        if ((*last)==val)temp++;
        cnt1++, last++;
    }
    ret-=(cnt[sec][val]-temp);

    for (int i=fir; i<=sec; i++) {
        ret+= cnt[i][val];
    }
    return ret;
}
int main() {
    int t, type, from, to, val;
    readI(N);
    SQ = 2048;
    for (int i=0; i<N; i++) {
        readI(t);
        val = i/SQ;
        a[val].push_back(t), ++cnt[val][t];
    }
    readI(Q);
    int lastans = 0;
    for (int i=0; i<Q; i++)  {
        scanf("%d %d %d", &type, &from, &to);
        from = ((from + lastans - 1) % N) + 1;
        to = ((to + lastans - 1) % N) + 1;
        if (from > to) swap(from, to);
        to--, from--;
        if (type == 1) {
            shiftRight(from, to);
        } else {
            readI(val);
            val = ((val + lastans - 1) % N) + 1;
            lastans = calc(from, to, val);
            printf("%d\n", lastans);
        }
    }


    return 0;
}