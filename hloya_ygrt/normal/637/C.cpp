#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const int sz = 3;
const double eps=1e-9;
const int maxn = 1e3+500, base = 1e9+7,maxm= 10;

string s[maxn];
int main()
{
    fast_io;
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout<<6<<endl;
        return 0;
    }
    int k = inf;
    for (int i=0;i<n;i++)
        cin >> s[i];
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++){
        int eq = 0;
        for (int b=0;b<6;b++)
            if (s[i][b] == s[j][b])
                eq++;
        if (eq == 0 || eq == 1)
            k = min(k, 2);
        if (eq == 3 || eq == 2)
            k = min(k, 1);
        if (eq >= 4)
            k = min(k, 0);
    }

    cout<<k;
}