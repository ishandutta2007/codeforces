#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

const int inf = 1e6;
int n, k;
int arr[inf];

int s1(){
    /*int n, k;
    cin >> n >> k;
    rep(i, 0, n){
        cin >> arr[i];
    }*/
    vector <int> not_1;
    not_1.push_back(-1);
    if (arr[0] == 1){
        not_1.push_back(0);
    }
    int nex, l, r, m, p, s, ans = 0;
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; ++i){
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    rep(i, 0, n){
        nex = i;
        if (i != 0 && arr[i - 1] != 1){
            not_1.push_back(i - 1);
        }
        p = arr[i];
        for (int j = (int)not_1.size() - 1; j >= max(0ll, (int)not_1.size() - 62); --j){
            l = not_1[j] + 1;
            r = nex + 1;
            if (p > (2e18 + arr[not_1[j]] - 1) / arr[not_1[j]]){
                break;
            }
            if (i == 2 && j == 0){
                /*cout << p << endl;
                cout << l << " " << r << endl;*/
            }
            while (r - l > 1){
                // cout << i << " " << j << endl;
                m = (l + r) / 2;
                if (p > k * (pref[i + 1] - pref[m])){
                    r = m;
                }
                else{
                    l = m;
                }
            }
            if (p == k * (pref[i + 1] - pref[l])){
                ans++;
                // cout << j << endl;
                // cout << p << " " << s + nex - l - 1 << endl;
                // cout << "answer is " << l << " " << i << endl;
            }
            p *= arr[not_1[j]];
            nex = not_1[j];
        }
    }
    return ans;
}

int s2(){
    int ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i; ++j){
            int p = 1, s = 0;
            for (int l = j; l <= i; ++l){
                p *= arr[l];
                s += arr[l];
            }
            if (p == s * k){
                ans++;
            }
        }
    }
    return ans;
}

main(){
    cin >> n >> k;
    rep(i, 0, n){
        cin >> arr[i];
    }
    // cout << s1() << " " << s2() << endl;
    cout << s1();
}