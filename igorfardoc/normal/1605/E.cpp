#include<bits/stdc++.h>
#define MAX 200000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[MAX + 1];
int func[MAX + 1];
int st[MAX + 1];




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vi pr;
    func[1] = 1;
    for(int i = 2; i <= MAX; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            func[i] = -1;
            st[i] = i;
        }
        for(int j = 0; j < pr.size() && pr[j] * i <= MAX && pr[j] <= lp[i]; j++) {
            lp[pr[j] * i] = pr[j];
            if(st[i] == i && pr[j] == lp[i]) {
                func[pr[j] * i] = 0;
                st[pr[j] * i] = pr[j] * i;
            } else {
                if(lp[i] == pr[j]) {
                    st[pr[j] * i] = st[i] * lp[i];
                } else {
                    st[pr[j] * i] = pr[j];
                }
                //cout << 1 << endl;
                func[pr[j] * i] = func[st[pr[j] * i]] * func[pr[j] * i / st[pr[j] * i]];
                //cout << 2 << endl;
            }
        }
    }
    /*for(int i = 1; i < 20; i++) {
        cout << func[i] << ' ';
    }*/
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    b[0] = 0;
    auto a1 = a;
    map<ll, int> d;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        //ans += abs(a1[i - 1] - b[i - 1]);
        if(func[i] == 1) {
            ++d[a1[i - 1] - b[i - 1]];
        } else if(func[i] == -1) {
            ++d[b[i - 1] - a1[i - 1]];
        } else {
            ans += abs(a1[i - 1] - b[i - 1]);
        }
        for(int j = i + i; j <= n; j+=i) {
            a1[j - 1] += b[i - 1] - a1[i - 1];
        }
    }
    vector<ll> ans1(1000000);
    int amright = 0;
    int amleft = 0;
    for(const auto& el : d) {
        //cout << el.first << ' ' << el.second << endl;
        if(el.first <= 1) {
            amleft += el.second;
        } else {
            amright += el.second;
        }
        ans += el.second * abs(el.first - 1);
    }
    auto it = d.begin();
    while(it != d.end() && (*it).first <= 1) {
        ++it;
    }
    for(int i = 1; i <= 1000000; i++) {
        ans1[i] = ans;
        while(it != d.end() && (*it).first <= i) {
            amleft += (*it).second;
            amright -= (*it).second;
            ++it;
        }
        ans += amleft;
        ans -= amright;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int qu;
        cin >> qu;
        cout << ans1[qu] << '\n';
    }

}