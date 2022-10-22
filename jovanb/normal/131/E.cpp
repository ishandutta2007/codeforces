#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int f1[200005];
int f2[200005];
int f3[200005];
int f4[200005];
int l1[200005];
int l2[200005];
int l3[200005];
int l4[200005];
int res[9];
int a[100005];
int b[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a[i] >> b[i];
        if(!f1[a[i]]) f1[a[i]] = b[i];
        else f1[a[i]] = min(f1[a[i]], b[i]);
        l1[a[i]] = max(l1[a[i]], b[i]);
        if(!f2[b[i]]) f2[b[i]] = a[i];
        else f2[b[i]] = min(f2[b[i]], a[i]);
        l2[b[i]] = max(l2[b[i]], a[i]);
        if(!f3[a[i]+b[i]]) f3[a[i]+b[i]] = a[i];
        else f3[a[i]+b[i]] = min(f3[a[i]+b[i]], a[i]);
        l3[a[i]+b[i]] = max(l3[a[i]+b[i]], a[i]);
        if(!f4[n-a[i]+b[i]]) f4[n-a[i]+b[i]] = a[i];
        else f4[n-a[i]+b[i]] = min(f4[n-a[i]+b[i]], a[i]);
        l4[n-a[i]+b[i]] = max(l4[n-a[i]+b[i]], a[i]);
    }
    for(int i=1; i<=m; i++){
        int cnt = 8;
        if(f1[a[i]] == b[i]) cnt--;
        if(l1[a[i]] == b[i]) cnt--;
        if(f2[b[i]] == a[i]) cnt--;
        if(l2[b[i]] == a[i]) cnt--;
        if(f3[a[i]+b[i]] == a[i]) cnt--;
        if(l3[a[i]+b[i]] == a[i]) cnt--;
        if(f4[n-a[i]+b[i]] == a[i]) cnt--;
        if(l4[n-a[i]+b[i]] == a[i]) cnt--;
        res[cnt]++;
    }
    for(int i=0; i<=8; i++){
        cout << res[i] << " ";
    }
    return 0;
}