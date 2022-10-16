#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
struct query{
    int l, r, ans, id;
};
int grp;
bool cmp1(query a, query b) {
    if(a.l / grp == b.l / grp) return a.r < b.r;
    return a.l < b.l;
}
int currl = -1, currr = -1;
int ans = 0;
int cnt[300005];
int ccnt[300005];
int arr[300005];
int as(int l, int r) {
    if(currl == -1) {
        //cout << l << ' ' << r << '\n';
        //cnt.clear();
        //while(!frq.empty()) frq.pop();
        ccnt[0] = 9999999;
        ccnt[1] = ans = 1;
        cnt[arr[l]]++;
        currl = currr = l;
    }
    while(currr < r) {
        currr++;
        cnt[arr[currr]]++;
        ccnt[cnt[arr[currr]]]++;
    }
    while(currl > l) {
        currl--;
        cnt[arr[currl]]++;
        ccnt[cnt[arr[currl]]]++;
    }
    while(currl < l) {
        ccnt[cnt[arr[currl]]]--;
        cnt[arr[currl]]--;
        currl++; 
    }
    while(currr > r) {
        ccnt[cnt[arr[currr]]]--;
        cnt[arr[currr]]--;
        currr--; 
    }
    while(ccnt[ans + 1]) ans++;
    while(!ccnt[ans]) ans--;
    //cout << frq.top().fi << ' ' << frq.top().se << '\n';
    int rng = r - l + 1;
    int dkl = 0, dkr = rng;
    //cout << ans << ' ' << rng << '\n';
    while(dkl != dkr) {
        int mm = (dkl + dkr) / 2;
        if((rng - mm + 1) / 2 < ans - mm) dkl = mm + 1;
        else dkr = mm;
    }
    return dkl + 1;
}
bool cmp2(query a, query b){return a.id < b.id;}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q; 
    grp = sqrt(n);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    query ask[q + 5];
    for(int i = 0; i < q; i++) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].id = i;
    }
    sort(ask, ask + q, cmp1);
    for(int i = 0; i < q; i++) ask[i].ans = as(ask[i].l, ask[i].r);
    sort(ask, ask + q, cmp2);
    for(int i = 0; i < q; i++) cout << ask[i].ans << '\n';
    return 0;
}