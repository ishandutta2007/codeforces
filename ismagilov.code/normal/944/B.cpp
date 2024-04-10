#include <bits/stdc++.h>
#define int long long
#define fs first
#define sc second
#define mp make_pair
#define vc vector
#define pr pair
#define pb push_back
#define ld long double
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()
#define endl "\n"
#define in cin
#define out cout

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    map<int, int> kek;
    int n;
    in >> n;
    int mini = 1000000000;
    vc<int> ked;
    for (int i = 0; i < n; i++){
        int x;
        in >> x;
        kek[x]++;
        ked.pb(x);
        mini = min(mini, x);
    }
    vc<int> mem(3);
    int sum = 0;
    for (auto v : kek){
        mem[v.fs - mini] = v.sc;
        sum += (v.fs - mini) * v.sc;
    }
    while(mem.back() == 0){
        mem.pop_back();
    }
    if (len(mem) == 1 || len(mem) == 2){
        out << n << endl;
        for (auto v : ked){
            out << v << ' ';
        }
        return 0;
    }
    pr<int, int> maxi = mp(n, mem.back());
    for (int i = 0; i < n; i++){
        if (sum >= i * 2){
            int sum1 = sum - i * 2;
            if (sum1 + i <= n){
                maxi = min(maxi, mp(min(mem[0], n - (sum1 + i)) + min(mem[1], sum1) + min(mem[2], i), i));
            }
        }
    }
    out << maxi.fs << endl;
    int sum1 = sum - maxi.sc * 2;
    for (int i = 0; i < maxi.sc; i++){
        out << mini + 2 << ' ';
    }
    for (int i = 0; i < sum1; i++){
        out << mini + 1 << ' ';
    }
    for (int i = 0; i < n - sum1 - maxi.sc; i++){
        out << mini << ' ';
    }
}