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
    int n, a, b;
    in >> n >> a >> b;
    vc<int> kek;
    for (int i = 0; i < n; i++){
        kek.pb(i + 1);
    }
    int kem = 0;
    while(len(kek) > 1){
        if (len(kek) == 2){
            out << "Final!";
            return 0;
        }
        kem++;
        vc<int> kek1;
        for (int i = 0; i < len(kek); i += 2){
            if (kek[i] == a){
                if (kek[i + 1] == b) {
                    out << kem;
                    return 0;
                }
            }
                if (kek[i] == b){
                    if (kek[i + 1] == a){
                        out << kem;
                        return 0;
                    }
                }
            kek1.pb(kek[i + (kek[i + 1] == a || kek[i + 1] == b)]);
        }
        kek = kek1;
    }
}