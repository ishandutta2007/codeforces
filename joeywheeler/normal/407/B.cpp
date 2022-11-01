#include <cstdio>
#include <vector>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int bf(vector<int> &t, vector<int> &p, int c) {
    if (c == t.size()) return 0;
    else {
        t[c]++;
        if (t[c]&1) return 1 + bf(t,p,p[c]);
        else return 1 + bf(t,p,c+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    FO(i,0,n) scanf("%d", &p[i]), p[i]--;
    vector<int> m(n);
    FO(i,0,n) {
        if (p[i] == i) m[i] = 2;
        else {
            FO(j,p[i],i) m[i] = (m[i] + m[j]) % 1000000007;
            m[i] = (m[i] + 2) % 1000000007;
        }
        //printf("m[%d]=%d\n", i, m[i]);
    }
    //vector<int> t(n);
    //printf("%d\n", bf(t, p, 0));

    int r = 0;
    FO(i,0,n) {
        r = (r + m[i]) % 1000000007;
    }
    printf("%d\n", r);

    return 0;
}