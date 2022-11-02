#include <iostream>
using namespace std;

long long s[99], n, k, r[99][99];

bool cb(long long t)
{
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            r[i][j] = 0;
    r[0][0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            if (r[i-1][j-1] == 0)
                continue;
            for (int l = j; l <= n; l++)
                if (((s[l] - s[j-1]) & t) == t)
                    r[i][l] = 1;
        }
    }
    if (r[k][n] == 1)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    long long a;
    for (int i = 1; i <= n; i++){
        cin>>a;
        s[i] = s[i-1] + a;
    }
    long long t = 1, ts = 0;
    for (int i = 1; i <= 59; i++) t *= 2;
    while (t > 0){
        if (cb(ts+t))
            ts += t;
        t /= 2;
    }
    cout<<ts<<'\n';
    return 0;
}