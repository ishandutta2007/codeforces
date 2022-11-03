#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 300002;
ll t[MAXN], w[MAXN], num[MAXN];
map<ll, ll> st;

struct comp {
    bool operator()(ll &i, ll &j) {
        if (t[i] == t[j]) {
            return w[i] < w[j];
        }
        return t[i] > t[j];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> t[i] >> w[i];
        w[i] -= t[i];
        w[i]++;
        num[i] = i;
    }
    sort(num + 1, num + n, comp());
    ll teamNow = 1;
    ll sz = 0;
    while(t[num[teamNow]] > t[0]){
        st[w[num[teamNow]]]++;
        sz++;
        teamNow++;
    }
    ll min_place = teamNow;
    while(t[0] > 0 && !st.empty()){
        t[0] -= st.begin()->first;
        if(t[0] < 0){
            break;
        }
        st.begin()->second--;
        sz--;
        if(st.begin()->second <= 0){
            st.erase(st.begin()->first);
        }
        while(t[num[teamNow]] > t[0]){
            st[w[num[teamNow]]]++;
            sz++;
            teamNow++;
        }
        min_place = min(min_place, sz + 1);
    }
    cout << min_place;
    return 0;
}