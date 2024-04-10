#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

vector<ll> b, p, idx1, idx2, pref1, pref2, pref11, pref12;

bool comp1(int o1, int o2){
    if(p[o1] == p[o2]){
        if(b[o1] == b[o2]){
            return o1 < o2;
        }
        return b[o1] < b[o2];
    }
    return p[o1] < p[o2];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, c, d;
    cin >> n >> c >> d;
    ll x, y;
    char cha;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        cha = '\n';
        while(cha == '\n' || cha == ' '){
            cin >> cha;
        }
        if(cha == 'C'){
            idx1.push_back(i);
        }else{
            idx2.push_back(i);
        }
        b.push_back(x);
        p.push_back(y);
    }

    sort(idx1.begin(), idx1.end(), &comp1);
    sort(idx2.begin(), idx2.end(), &comp1);
    ll mx;
    mx = 0;
    pref11.push_back(0);
    for(int i = 0; i < idx1.size(); ++i){
        if(i) {
            if(b[idx1[i]] >= mx){
                pref11.push_back(mx);
            }else{
                if(b[idx1[i]] > pref11.back()){
                    pref11.push_back(b[idx1[i]]);
                }else{
                    pref11.push_back(pref11.back());
                }
            }
        }
        mx = max(mx, b[idx1[i]]);
        pref1.push_back(mx);
    }
    mx = 0;
    pref12.push_back(0);
    for(int i = 0; i < idx2.size(); ++i){
        if(i) {
            if(b[idx2[i]] >= mx){
                pref12.push_back(mx);
            }else{
                if(b[idx2[i]] > pref12.back()){
                    pref12.push_back(b[idx2[i]]);
                }else{
                    pref12.push_back(pref12.back());
                }
            }
        }
        mx = max(mx, b[idx2[i]]);
        pref2.push_back(mx);
    }
    for(int i = 0; i < idx1.size(); ++i){
        ll cur = p[idx1[i]];
        int l = 0, r = idx1.size(), mid;
        if(p[idx1[0]] + cur > c){
            continue;
        }
        if(p[idx1[idx1.size() - 1]] + cur <= c){
            if(i <= idx1.size() - 1 && b[idx1[i]] == pref1[idx1.size() - 1]){
                if(pref11[idx1.size() - 1] > 0) {
                    ans = max(ans, pref11[idx1.size() - 1] + b[idx1[i]]);
                }
            }else{
                ans = max(ans, pref1[idx1.size() - 1] + b[idx1[i]]);
            }
            continue;
        }
        while(r - l > 1){
            mid = (l + r) >> 1;
            if(p[idx1[mid]] + cur > c){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(i <= l && b[idx1[i]] == pref1[l]){
            if(pref11[l] > 0) {
                ans = max(ans, pref11[l] + b[idx1[i]]);
            }
        }else{
            ans = max(ans, pref1[l] + b[idx1[i]]);
        }
    }

    for(int i = 0; i < idx2.size(); ++i){
        ll cur = p[idx2[i]];
        int l = 0, r = idx2.size(), mid;
        if(p[idx2[0]] + cur > d){
            continue;
        }
        if(p[idx2[idx2.size() - 1]] + cur <= d){
            if(i <= idx2.size() - 1 && b[idx2[i]] == pref2[idx2.size() - 1]){
                if(pref12[idx2.size() - 1] > 0) {
                    ans = max(ans, pref12[idx2.size() - 1] + b[idx2[i]]);
                }
            }else{
                ans = max(ans, pref2[idx2.size() - 1] + b[idx2[i]]);
            }
            continue;
        }
        while(r - l > 1){
            mid = (l + r) >> 1;
            if(p[idx2[mid]] + cur > d){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(i <= l && b[idx2[i]] == pref2[l]){
            if(pref12[l] > 0) {
                ans = max(ans, pref12[l] + b[idx2[i]]);
            }
        }else{
            ans = max(ans, pref2[l] + b[idx2[i]]);
        }
    }
    if(idx2.size() > 0 && idx1.size() > 0) {

        int l = 0, r = idx1.size(), mid;
        if (p[idx1[0]] > c) {
            l = -1;
        }else {
            if (p[idx1[idx1.size() - 1]] <= c) {
                l = idx1.size() - 1;
            }else {
                while (r - l > 1) {
                    mid = (l + r) >> 1;
                    if (p[idx1[mid]] > c) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
            }
        }

        int l2 = 0, r2 = idx1.size(), mid2;
        if (p[idx2[0]] > d) {
            l2 = -1;
        }else {
            if (p[idx2[idx2.size() - 1]] <= d) {
                l2 = idx2.size() - 1;
            }else {
                while (r2 - l2 > 1) {
                    mid2 = (l2 + r2) >> 1;
                    if (p[idx2[mid2]] > d) {
                        r2 = mid2;
                    } else {
                        l2 = mid2;
                    }
                }
            }
        }
        if(l != -1 && l2 != -1){
            ans = max(ans, pref1[l] + pref2[l2]);
        }
    }
    cout << ans << endl;
    return 0;
}