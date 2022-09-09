#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>

using namespace std;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "% lld"
#endif

typedef long long ll;

const double eps=1e-10;

int main()
{
    int n,r,R;
    cin >> n >> R >> r;
    if (n==1)
    {
        if (r<=R) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if (r>1.0*R/2)
    {
        cout << "NO";
        return 0;
    }
//    cerr << M_PI/n << ' ' << asin(1.0*r/(R-r)) << endl;
    if (M_PI/n>asin(1.0*r/(R-r))-eps) cout << "YES";
    else cout << "NO";
    return 0;
}