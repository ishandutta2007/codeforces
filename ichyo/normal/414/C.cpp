#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long LL;

void merge_sort(vector<int>& a, vector<LL>& cnt, vector<LL>& cnt2, int level){
    int n = a.size();
    if(n <= 1) return ;
    vector<int> b(a.begin(), a.begin() + n / 2);
    vector<int> c(a.begin() + n / 2, a.end());

    merge_sort(b, cnt, cnt2, level + 1);
    merge_sort(c, cnt, cnt2, level + 1);

    b.push_back(INT_MAX);
    c.push_back(INT_MAX);

    int ai = 0, bi = 0, ci = 0;
    while(ai < n){
        if(b[bi] == c[ci]){
            int t = b[bi];
            int len_b = 0;
            while(b[bi] == t){
                a[ai++] = b[bi++];
                len_b++;
            }
            while(c[ci] == t){
                a[ai++] = c[ci++];
                cnt2[level] += len_b;
                cnt[level] += n / 2 - bi;
            }
        }else if(b[bi] < c[ci]){
            a[ai++] = b[bi++];
        }else if(b[bi] > c[ci]){
            cnt[level] += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
}

void solve(int n, vector<int> a){
    int m;
    cin >> m;
    vector<LL> cnt(30);
    vector<LL> cnt2(30);
    merge_sort(a, cnt, cnt2, 0);
    while(m--){
        int q;
        scanf("%d", &q);
        int lv = n - q;
        for(int i = lv; i < n; i++){
            cnt[i] = (1LL << (2 * n - i - 2)) - cnt[i] - cnt2[i];
        }
        LL ans = 0;
        for(int i = 0; i < n; i++){
            ans += cnt[i];
        }
        printf("%I64d\n", ans);
    }
}

int main(){
    int n;
    while(cin >> n){
        vector<int> a(1 << n);
        REP(i, (1 << n)) scanf("%d", &a[i]);
        solve(n, a);
    }
    return 0;
}