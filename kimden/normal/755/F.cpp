#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

const int MAXN = 1001001;
int p[MAXN];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
//    ll twos = 0;
//    ll sum = 0;
//    ll odds = 0;
    ll num = 0;
    for(int i = 0; i < n; i++){
        if(p[i] == -1){
            continue;
        }
        int cur = i;
        int cnt = 0;
        do{
            int tmp = p[cur];
            p[cur] = -1;
            cur = tmp;
            cnt++;
        }while(cur != i);
        v.push_back(cnt);
//        twos += (cnt / 2);
//        odds += (cnt % 2);
//        sum += cnt;
        num++;
    }
    sort(v.begin(), v.end());
    map<int, int> mp;
    for(int i = 0; i < v.size(); i++){
        mp[v[i]]++;
    }
    int k1, ans;
    k1 = k;
    ans = 0;
    vector<int> busy, free;
    ll sum = 0;
    ll total = 0;
    bool tmptmp = false;
    for(int i = 0; i < v.size(); i++){
        if(rand() % 2) {
            free.push_back(i);
        }else{
            busy.push_back(i);
            sum += v[i];
        }
        total += v[i];
        if(v[i] == k){
            tmptmp = true;
        }
    }
    int idx;
    if(tmptmp || total == k){
        cout << k << " ";
    }else if(total < k){
        cout << k + 1 << " ";
    }else{
        for (int i = 0; i < 1000000; i++) {
            if (sum < k) {
                idx = (int)(rand() % free.size());
                busy.push_back(free[idx]);
                sum += v[free[idx]];
                swap(free[idx], free[free.size() - 1]);
                free.pop_back();
            } else if(sum > k) {
                idx = (int)(rand() % busy.size());
                free.push_back(busy[idx]);
                sum -= v[busy[idx]];
                swap(busy[idx], busy[busy.size() - 1]);
                busy.pop_back();
            } else {
                break;
            }
        }
        if(sum == k){
            cout << k << " ";
        }else{
            cout << k + 1 << " ";
        }
    }
    k1 = k;
    ans = 0;
    int o1 = 0;
    for(int i = 0; i < v.size(); i++){
        if(k1 >= v[i] / 2){
            k1 -= v[i] / 2;
            ans += v[i] - (v[i] % 2);
            o1 += (v[i] % 2);
            continue;
        }else{
            ans += 2 * k1;
            k1 = 0;
            break;
        }
    }
    if(k1 > 0){
        ans += min(o1, k1);
    }
    cout << ans << endl;
    return 0;
}