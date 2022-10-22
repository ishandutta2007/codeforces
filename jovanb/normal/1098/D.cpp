#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int LOG = 30;

multiset <int> q[LOG+1];
ll sum[LOG+1];
ll mn[LOG+1];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int qrs;
    cin >> qrs;
    int svi = 0, res = 0;
    while(qrs--){
        char t;
        int x;
        cin >> t >> x;
        int m = 0;
        while((1 << (m + 1)) <= x) m++;
        if(t == '+'){
            svi++;
            ll sm = 0;
            for(int i=0; i<m; i++) sm += sum[i];
            if(mn[m] > 2*sm) res--;
            q[m].insert(x);
            sum[m] += x;
            mn[m] = *q[m].begin();
            if(mn[m] > 2*sm) res++;
            for(int i=m+1; i<=LOG; i++){
                sm += sum[i-1];
                if(mn[i] <= 2*sm && mn[i] > 2*(sm - x)) res--;
            }
        }
        else{
            svi--;
            ll sm = 0;
            for(int i=0; i<m; i++) sm += sum[i];
            if(mn[m] > 2*sm) res--;
            q[m].erase(q[m].find(x));
            sum[m] -= x;
            if(q[m].size()) mn[m] = *q[m].begin();
            else mn[m] = 0;
            if(mn[m] > 2*sm) res++;
            for(int i=m+1; i<=LOG; i++){
                sm += sum[i-1];
                if(mn[i] > 2*sm && mn[i] <= 2*(sm + x)) res++;
            }
        }
        cout << svi - res << "\n";
    }
    return 0;
}