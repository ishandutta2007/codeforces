#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vi a;

pair<int, int> q(int l, int r) {
    printf("? %d %d\n", l + 1, r + 1);
    fflush(stdout);
    pair<int, int> p;
    scanf("%d %d", &p.first, &p.second);
    return p;
}
void ans() {
    printf("! ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    fflush(stdout);
}

void rec(int l, int r) {
    if(l > r) {
        return;
    }
    if(a[l - 1] == a[r + 1]) {
        for(int i = l; i <= r; i++) {
            a[i] = a[l - 1];
        }
        return;
    }
    int mid = (l + r) / 2;
    auto p = q(l - 1, r + 1);
    if(a[l - 1] == p.first && p.second != 1) {
        for(int i = l; i < l - 1 + p.second; i++) {
            a[i] = p.first;
        }
        rec(l + p.second - 1, r);
    } else if(a[r + 1] == p.first && p.second != 1) {
        for(int i = r - p.second + 2; i <= r; i++) {
            a[i] = p.first;
        }
        rec(l, r - p.second + 1);
    } else {
        p = q(mid, mid);
        a[mid] = p.first;
        rec(l, mid - 1);
        rec(mid + 1, r);
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    a.resize(n);
    auto p = q(0, 0);
    a[0] = p.first;
    if(n == 1) {
        ans();
        return 0;
    }
    p = q(n - 1, n - 1);
    a[n - 1] = p.first;
    rec(1, n - 2);
    ans();
}