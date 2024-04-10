/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int N = 1e5 + 5;

bool np[N];

int queryB(int a) {
    cout << "B " << a << endl;
    int res; cin >> res; return res;
}

int queryA(int a) {
    cout << "A " << a << endl;
    int res; cin >> res; return res;
}

int calc(vector<int> pr) {
    int sz = queryA(1);
    while (pr.size()) {
//        for (auto v : pr)
//            cout << v << " ";
//        cout << endl;
        int psz = pr.size();
        int lsz = psz + 1 >> 1;
        int rsz = sz - lsz;
        for (int i = 0; i < lsz; i++)
            if (queryB(pr[i]) >= 2) return pr[i];
        sz = queryA(1);
        if (sz != rsz){
            for (int i = 0; i < lsz; i++)
                if (queryB(pr[i])) return pr[i];
        }
        vector<int> tmp(pr.begin() + lsz, pr.end());
        pr = tmp;
    }
    return 1;
}

void Hollwo_Pelw() {
    int n; cin >> n;
    vector<int> prs;

    np[0] = np[1] = 1;
    for (int i = 1; i <= n; i++){
        if (!np[i]) {
            prs.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                np[j] = 1;
        }
    }
    vector<int> bigs;
    for (auto p : prs){
        if (1ll * p * p <= n)
            queryB(p);
        else
            bigs.push_back(p);
    }

//    for (auto v : bigs)
//        cout << v << " ";
//    cout << endl;

    int ans = calc(bigs);

    for (auto p : prs) {
        while (1ll * p * p <= n && 1ll * ans * p <= n && queryB(ans * p))
            ans *= p;
    }
    cout << "C " << ans << endl;
}