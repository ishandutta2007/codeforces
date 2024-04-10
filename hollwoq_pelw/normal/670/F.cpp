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
        FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
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

string s, t;
int scnt[10], tmpcnt[10];

bool del_len(int len) {
    int sz = 0, val = len;
    for (; len; len /= 10, ++ sz)
        if (-- tmpcnt[len % 10] < 0) return 0;
    // cout << sz << ' ' << len << "\n";
    return (int) s.size() == sz + val;
}

bool check() {
    for (int i = 1; i < t.size(); i++) {
        if (t[i] > t[i - 1]) return 1;
        if (t[i] < t[i - 1]) return 0;
    }
    return 0;
}

void solve(int len){
    // cout << len << "\n";
    for (int i = 0; i < 10; i++)
        tmpcnt[i] = scnt[i];
    if (!del_len(len)) return ;

    string mid = t, head = "", tail = "";

    string res = string(len, '9');
    if (mid[0] != '0') {
        res = mid;
        for (int i = 0; i < 10; i++)
            res += string(tmpcnt[i], '0' + i);
    }

    bool ok = 0;
    for (int _ = 0; _ < mid[0] - '0'; _++)
        if (tmpcnt[_]) ok = 1;

    for (int i = 1; i < (mid[0] != '0' ? mid[0] - '0' + (check() || ok): 10); i++)
        if (head == "" && tmpcnt[i]) head += (char) ('0' + i), tmpcnt[i] --;

    if (head != "") 
        for (int i = 0; i < (mid[0] - '0' + check()); i++)
            head += string(tmpcnt[i], '0' + i), tmpcnt[i] = 0;
    
    for (int i = 0; i < 10; i ++)
        tail += string(tmpcnt[i], '0' + i);
    
    cout << min(res, head + mid + tail);

    exit(0);
}

void Hollwo_Pelw() {
    cin >> s >> t;
    for (auto c : s) scnt[c - '0'] ++;
    for (auto c : t) scnt[c - '0'] --;
    for (int i = max(1, (int) s.size() - 10); i < (int) s.size(); i++)
        solve(i);
}