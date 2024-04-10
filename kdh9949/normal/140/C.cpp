#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010], aa[100010];
int cnt[100010];
int asdf[100010][3];
priority_queue<pair<int, int> > pq;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < n; i++) aa[i] = a[i];
    sort(aa, aa + n);
    for(int i = 0; i < n; i++) a[i] = (int)(lower_bound(aa, aa + n, a[i]) - aa);
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    for(int i = 0; i < n; i++) if(cnt[i]) pq.push(make_pair(cnt[i], i));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(pq.empty()) break;
        pair<int, int> x = pq.top(); pq.pop(); if(pq.empty()) break;
        pair<int, int> y = pq.top(); pq.pop(); if(pq.empty()) break;
        pair<int, int> z = pq.top(); pq.pop();
        if(--x.first) pq.push(x);
        if(--y.first) pq.push(y);
        if(--z.first) pq.push(z);
        asdf[i][0] = x.second; asdf[i][1] = y.second; asdf[i][2] = z.second;
        ans++;
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++){
        vector<int> v;
        for(int j = 0; j < 3; j++) v.push_back(aa[asdf[i][j]]);
        sort(v.begin(), v.end());
        for(int j = 2; j >= 0; j--) printf("%d ", v[j]);
        puts("");
    }
}