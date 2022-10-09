#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int MAXVAL = 1000010;
int a[MAXN];
bool has[MAXVAL];
bool cant[MAXVAL];
void solve(){
    vector<int> razlike;
    memset(has, false, sizeof has);
    memset(cant, false, sizeof cant);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            razlike.push_back(abs(a[i] - a[j]));
        }
    }
    sort(razlike.begin(), razlike.end());
    razlike.resize(unique(razlike.begin(), razlike.end()) - razlike.begin());
    vector<int> b;
    for(int num = 1; num <= 1000000 && (int)b.size() < n; num++){
        if(!cant[num]){
            b.push_back(num);
            for(auto x : razlike) if(num + x < MAXVAL) cant[num + x] = true;
        }
    }
    if((int)b.size() < n) puts("NO");
    else {
        puts("YES");
        for(auto x : b) printf("%d ", x);
        printf("\n");
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}