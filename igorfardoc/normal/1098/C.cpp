#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    ll s;
    cin >> n >> s;
    if(s > (ll)n * (n + 1) / 2) {
        cout << "No";
        return 0;
    }
    for(int i = 1; i <= n - 1; i++) {
        ll now = 1;
        ll ans = 1;
        int other = n - 1;
        int it = 2;
        while(other > 0) {
            now *= i;
            int here = min((ll)other, now);
            other -= here;
            ans += (ll)it * here;
            ++it;
        }
        if(s < ans) continue;
        cout << "Yes\n";
        vi p(n + 1);
        vi zn(n + 1);
        vi prev = {1};
        other = n - 1;
        now = 1;
        vi fir = {1};
        set<int> firs;
        it = 2;
        while(other > 0) {
            now *= i;
            int here = min((ll)other, now);
            other -= here;
            int last = prev.back();
            vi prevnow;
            for(int j = 0; j < here; j++) {
                p[j + last + 1] = prev[j / i];
                zn[j + last + 1] = it;
                prevnow.push_back(j + last + 1);
                if(j == 0) fir.push_back(j + last + 1);
            }
            swap(prev, prevnow);
            ++it;
        }
        for(const auto& el : fir) {
            firs.insert(el);
        }
        s -= ans;
        for(int j = n; j >= 2; j--) {
            if(s == 0) break;
            if(firs.find(j) != firs.end()) continue;
            int lvl = zn[j];
            int here = min(s, (ll)fir.size() + 1 - lvl);
            s -= here;
            p[j] = fir[lvl - 2 + here];
            if(s != 0) {
                fir.push_back(j);
            }
        }
        for(int i = 2; i <= n; i++) {
            cout << p[i] << ' ';
        }/*
        cout << endl;
        for(const auto& el : fir) {
            cout << el << ' ';
        }*/
        return 0;
    }
    cout << "No";

}