#include<bits/stdc++.h>
#include<set>
using namespace std;
int main() { 
    set<int> s;
    int n,m,k;
    
    cin >> n;
    int a[n];
    
    for (int t = 0; t < n; t ++){
        cin >> k;
        a[t] = k;
        s.insert(k);
    }
    
    cin >> m;
    int b[m];
    
    for (int t = 0; t < m; t ++){
        cin >> k;
        b[t] = k;
        s.insert(k);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++){
            if (!s.count(a[i]+b[j])){
                cout << a[i] << ' ' << b[j];
                return 0;
            }
        }
    }
    return 0;
}