#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAX 1000010

int N;
char S[MAX];
int A[MAX];

int ans[MAX];

int b, s[2];
int a(int i) {
    return (i == b) ? A[i] : s[A[i]];
}

int main() {
    int i;
    
    for (; gets(S); ) {
        N = strlen(S);
        for (i = 0; i < N; ++i) {
            A[i] = S[N - 1 - i] - '0';
        }
//cout<<"A : ";pv(A,A+N);
        for (b = 0; !A[b]; ++b);
//cout<<"b = "<<b<<endl;
        memset(ans, 0, sizeof(ans));
        s[0] = 0; s[1] = 1;
        for (i = N - 1; i >= b; --i) {
//for(int j=b;j<=i;++j)cout<<a(j);cout<<endl;
            if (a(i)) {
                if (i == b || a(i - 1) == 0) {
                    ans[i] += s[0] ? -1 : +1;
                } else {
                    ans[i + 1] += s[0] ? -1 : +1;
                    swap(s[0], s[1]);
                }
            }
        }
        int ansCnt = 0;
        for (i = 0; i <= N; ++i) if (ans[i]) {
            ++ansCnt;
        }
        printf("%d\n", ansCnt);
        for (i = 0; i <= N; ++i) if (ans[i]) {
            printf("%c2^%d\n", (ans[i] < 0) ? '-' : '+', i);
        }
    }
    
    return 0;
}