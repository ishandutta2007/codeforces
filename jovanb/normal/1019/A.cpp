#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair <int, int> niz[100005];
int br[100005];
int brr[100005];
int n, m;
bool used[100005];

ll resi(int x){
    ll sum = 0;
    for(int i=1; i<=m; i++) brr[i] = br[i];
    for(int i=1; i<=n; i++) used[i] = 0;
    int k = br[1];
    for(int i=1; i<=n; i++){
        int j = niz[i].second;
        int val = niz[i].first;
        if(j == 1) continue;
        if(brr[j] >= x){
            brr[j]--;
            k++;
            sum += val;
            used[i] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        int j = niz[i].second;
        int val = niz[i].first;
        if(j == 1) continue;
        if(k < x && !used[i]){
            used[i] = 1;
            k++;
            sum += val;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> niz[i].second >> niz[i].first;
        br[niz[i].second]++;
    }
    sort(niz+1, niz+1+n);
    ll mn = resi(1);
    for(int i=2; i<=n; i++){
        mn = min(mn, resi(i));
    }
    cout << mn;
    return 0;
}