#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];
int res[100005];
int ls[100005];

int cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    res[n] = -1;
    ls[++cnt] = n;
    for(int i=n-1; i>=1; i--){
        if(niz[i] < niz[ls[cnt]]){ls[++cnt] = i; res[i] = -1; continue;}
        if(niz[i] == niz[ls[cnt]]){res[i] = -1; continue;}
        int l=1, r=cnt, maxres=cnt;
        while(l <= r){
            int mid = (l+r)/2;
            if(niz[ls[mid]] < niz[i]){r = mid-1; maxres = mid;}
            else l = mid+1;
        }
        res[i] = ls[maxres]-i-1;
    }
    for(int i=1; i<=n; i++){
        cout << res[i] << " ";
    }
    return 0;
}