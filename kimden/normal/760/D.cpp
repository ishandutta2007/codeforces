#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//const ll mod = 1000000007;
//const ld eps = 1e-8;
const int MAXN = 100002;
const ll one = 20;
const ll big = 50;
const ll huge = 120;
const ll tbig = 90;
const ll thuge = 1440;

ll t[MAXN];
ll sum[MAXN];
ll delta[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> t[i];
    }
    t[0] = -2 * thuge;
    sum[0] = 0;
    delta[0] = 0;
    int bigidx = 1, hugeidx = 1;
    int left, right, mid;
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + one;

        left = bigidx;
        right = i - 1;
        while(left < right){
            mid = ((left + right) >> 1);
            if(t[i] - t[mid] < tbig){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        bigidx = left;
        if(left < i){
            sum[i] = min(sum[i], sum[left - 1] + big);
        }


        left = hugeidx;
        right = i - 1;
        while(left < right){
            mid = ((left + right) >> 1);
            if(t[i] - t[mid] < thuge){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        hugeidx = left;
        if(left < i){
            sum[i] = min(sum[i], sum[left - 1] + huge);
        }


        delta[i] = sum[i] - sum[i - 1];
    }
    for(int i = 1; i <= n; i++){
        cout << delta[i] << endl;
    }
    return 0;
}