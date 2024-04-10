#include <bits/stdc++.h>
using namespace std;
int sol, solmax, a[1009], n, ans, nzero;
unordered_map<int, int> m;

int dfs(int k1, int k2, int lvl)
{
    // cerr << k1 << ' ' << k2 << ' ' << m[k1 + k2] << '\n';
    if(m.find(k1+k2)!=m.end() && m[k1+k2] > 0) {    
        m[k1+k2]--;
        dfs(k2, k1+k2, lvl + 1);
        m[k1+k2]++;
    }
    else 
        ans = max(ans, lvl);
}
 
int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i] == 0) nzero++;
        m[a[i]]++;
    }
        
    ans = nzero;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && (a[j] != 0 || a[i] != 0)) {
                m[a[i]]--;
                m[a[j]]--;
                dfs(a[i], a[j], 2);
                m[a[i]]++;
                m[a[j]]++;
            }
    cout << ans << '\n';
    return 0;
}