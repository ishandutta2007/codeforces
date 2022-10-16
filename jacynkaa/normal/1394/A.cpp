#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
#define what(x) cerr << #x << " is " << x << endl;
#define PII pair<int, int>
#define int long long


int32_t main()
{
    int n,d,m;
    cin>>n>>d>>m;
    vector<int> wieksze;
    vector<int> mniejsze={(int)(2e9)};
    rep(i,n)
        {
        int a;
        cin>>a;
        if(a>m) wieksze.push_back(a);
        else mniejsze.push_back(a);
        }

    sort(all(mniejsze), greater<int>());
    sort(all(wieksze), greater<int>());
    mniejsze[0]=0;
    for(int i=1;i<sz(mniejsze);i++) mniejsze[i]+=mniejsze[i-1];
    int res=-1;
    int sum=0;
    rep(i,sz(wieksze)+1)
    {
        int ile_mniejszych=n-max(0ll,(d+1)*(i-1)+1);
        if(ile_mniejszych>=0)
            res=max(res, sum+mniejsze[min(ile_mniejszych,sz(mniejsze)-1)]);

        if(i!=sz(wieksze))
            sum+=wieksze[i];
    }
    cout <<res<<endl;
}