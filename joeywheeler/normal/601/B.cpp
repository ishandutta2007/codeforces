#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll a[100005]; int n;
ll b[100005]; int m;
int l[100005];

ll calc() {
    ll r = 0;
    //printf("!");
    //FO(i,0,m) printf("%lld ", b[i]);
    //printf("\n");
    stack<pair<int, ll> > st;
    st.emplace(-1,1e9);
    FO(i,0,m) {
        while (st.top().second <= b[i]) st.pop();
        l[i] = st.top().first+1;
        //printf("l[%d]=%d\n", i, l[i]);
        st.emplace(i, b[i]);
    }
    st = stack<pair<int, ll> >();
    st.emplace(m,1e9);
    for (int i = m-1; i >= 0; i--) {
        while (st.top().second < b[i]) st.pop();
        r += (st.top().first-i) * 1ll * (i-l[i]+1) * b[i];
        st.emplace(i, b[i]);
    }
    return r;
}

int main() {
    int q;
    scanf("%d%d", &n, &q);
    FO(i,0,n) scanf("%lld", a+i);
    FO(i,0,q) {
        int l, r; scanf("%d%d", &l, &r); l--;
        FO(j,l+1,r) b[j-l-1] = abs(a[j]-a[j-1]);
        m = r-l-1;
        printf("%lld\n", calc());
    }
}