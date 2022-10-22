#include <bits/stdc++.h>
using namespace std;

int res[10005];
vector <pair <int, int>> vec;
int tr[100005];
int l[100005];
int r[100005];
int niz[1000005];

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x >= i){cout << "NO"; return 0;}
        tr[i] += x;
        l[i] = x;
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x > n-i){cout << "NO"; return 0;}
        tr[i] += x;
        r[i] = x;
        vec.push_back({tr[i], i});
    }
    sort(vec.begin(), vec.end());
    vector <int> vc;
    for(auto c : vec){
        vc.clear();
        int ind = c.second;
        int mn1 = 10005;
        int mn2 = 10005;
        for(int i=1; i<ind; i++){
            if(niz[i]) vc.push_back(niz[i]);
        }
        sort(vc.begin(), vc.end());
        reverse(vc.begin(), vc.end());
        if(l[ind] <= vc.size() && l[ind] > 0) mn1 = vc[l[ind]-1]-1;
        vc.clear();
        for(int i=ind+1; i<=n; i++){
            if(niz[i]) vc.push_back(niz[i]);
        }
        sort(vc.begin(), vc.end());
        reverse(vc.begin(), vc.end());
        if(r[ind] <= vc.size() && r[ind] > 0) mn2 = vc[r[ind]-1]-1;
        niz[ind] = min(mn1, mn2);
    }


    int mn = 10000000;
    for(int i=1; i<=n; i++){
        mn = min(mn, niz[i]);
        int tr=0;
        for(int j=1; j<i; j++) if(niz[j] > niz[i]) tr++;
        if(tr != l[i]){cout << "NO"; return 0;}
        tr = 0;
        for(int j=i+1; j<=n; j++) if(niz[j] > niz[i]) tr++;
        if(tr != r[i]){cout << "NO"; return 0;}
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++) cout << niz[i]-mn+1 << " ";
    return 0;
}