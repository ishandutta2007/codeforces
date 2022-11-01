#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*bool isGood(vector<int> v, bool orig = false) {
    int n = (int)v.size();
    if (n == 1)
        return false;
    bool beg = true;
    for (int i = 0; i < n; i++) {
        if (beg) {
            v[i] -= 1;
            beg = false;
        } else if (v[i] == 1 || i == n-1) {
            if (i != n-1 && orig)
                return false;
            v[i] = 0;
            beg = true;
        } else v[i] -= 2;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] < 0)
            return false;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        vector<int> nv;
        for (int j = i; j != n && v[j] != 0; j++)
        {
            nv.push_back(v[j]);
        }
        if (!isGood(nv))
            return false;
        i += -1 + (int)nv.size();
    }
    return true;
}*/

int main(void) {
    int N;
    scanf("%d", &N);
    typedef pair<int, int> pii;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
        if (i != 0 && a[i] > a[i-1] + 1) {
            printf("NO\n");
            return 0;
        }
    }
    vector< int > v(a[N-1]-a[0]+1);
    for (int i = 0; i < N; i++) {
        v[a[i]-a[0]]++;
    }
    int expectedNext = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (expectedNext < 1 && i != 0) {
            printf("NO\n");
            return 0;
        }
        expectedNext = 2*v[i] - expectedNext; 
    }
    if (expectedNext == 0)
        printf("YES\n");
    else printf("NO\n");
    /*if (isGood(v, true))
        printf("YES\n");
    else
        printf("NO\n");*/
    return 0;
}