#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, a, b, ans, l1 = 1000, l2, c1 = 900, c2, m, nr;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == 'B')
            {
                nr++;
                l1 = min(l1, i);
                l2 = max(l2, i);
                c1 = min(c1, j);
                c2 = max(c2, j);
            }
        }
    }

    int l = max(l2-l1, c2-c1) + 1;
    if(nr == 0) ans = 1;    
    else if(l > m || l > n) ans = -1;
    else ans = l*l - nr;
    cout << ans << '\n';
}