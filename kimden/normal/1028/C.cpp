#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    multiset<int> aa, bb, cc, dd;
    vector<int> a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        aa.insert(-a[i]);
        bb.insert(-b[i]);
        cc.insert(c[i]);
        dd.insert(d[i]);
    }
    for(int i = 0; i < n; ++i){
        aa.erase(aa.find(-a[i]));
        bb.erase(bb.find(-b[i]));
        cc.erase(cc.find(c[i]));
        dd.erase(dd.find(d[i]));
        int aaa = *aa.begin();
        int bbb = *bb.begin();
        int ccc = *cc.begin();
        int ddd = *dd.begin();
        if(-aaa <= ccc && -bbb <= ddd){
            cout << ccc << " " << ddd << endl;
            return 0;
        }
        aa.insert(-a[i]);
        bb.insert(-b[i]);
        cc.insert(c[i]);
        dd.insert(d[i]);
    }
    return 0;
}