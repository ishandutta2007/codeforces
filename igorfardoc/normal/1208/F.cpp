#include<bits/stdc++.h>
#define maxn 2000000
#define log 21
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
    cin >> n;
    vi a(n);
    vi max1(maxn + 1, -1);
    vi max2(maxn + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(max2[a[i]] = max1[a[i]]) {
            max1[a[i]] = i;
        }
    }
    for(int i = 0; i < log; i++) {
        for(int j = 0; j <= maxn; j++) {
            if(!((j >> i) & 1)) {
                int other = j ^ (1 << i);
                if(other > maxn) {
                    continue;
                }
                int max01 = max1[j];
                int max02 = max2[j];
                if(max1[other] > max01) {
                    max02 = max01;
                    max01 = max1[other];
                } else if(max1[other] > max02) {
                    max02 = max1[other];
                }
                if(max2[other] > max02) {
                    max02 = max2[other];
                }
                max1[j] = max01;
                max2[j] = max02;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        int anshere = 0;
        int here = 0;
        for(int j = log - 1; j >= 0; j--) {
            if((a[i] >> j) & 1) {
                anshere ^= (1 << j);
                continue;
            }
            here ^= (1 << j);
            if(max2[here] > i) {
                anshere ^= (1 << j);
            } else {
                here ^= (1 << j);
            }
        }
        ans = max(ans, anshere);
    }
    cout << ans;

}