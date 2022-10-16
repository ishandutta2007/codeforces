#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
vector<vector<int>> split(vector<int> a) {
    int n = a.size();
    vector<int> aa[4];
    for(int i = 0; i < n; i++) {
        aa[i % 4].pb(a[i]);
    }
    vector<vector<int>> r;
    for(int i = 0; i < 4; i++) {
        r.pb(aa[i]);
    }
    return r;
}
vector<int> merge(vector<vector<int>> a, vector<int> k) {
    vector<int> aa;
    for(auto x: k) {
        for(auto xx: a[x]) aa.pb(xx);
    }
    return aa;
}
bool ask(vector<int> a, vector<int> b) {
    cout << "? " << a.size() + b.size() << ' ';
    for(auto x: a) cout << x << ' ';
    for(auto x: b) cout << x << ' ';
    cout << endl;
    fflush(stdout);
    string ss;
    cin >> ss;
    return ss == "YES";
}
bool ask2(int x) {
    cout << "? 1 " << x << ' ';
    cout << endl;
    fflush(stdout);
    string ss;
    cin >> ss;
    return ss == "YES";
}
void solve(int TC) {
    int n;
    cin >> n;
    vector<int> t;
    for(int i = 1; i <= n; i++) t.pb(i);
    while(t.size() >= 4) {
        vector<vector<int>> aa = split(t);
        bool a = ask(aa[0], aa[1]);
        bool b = ask(aa[0], aa[2]);
        vector<int> k;
        if(a && b) {
            k.pb(0); k.pb(1); k.pb(2);
        }
        else if(a && !b) {
            k.pb(0); k.pb(1); k.pb(3);
        }
        else if(!a && b) {
            k.pb(0); k.pb(3); k.pb(2);
        }
        else {
            k.pb(3); k.pb(1); k.pb(2);
        }
        t = merge(aa, k);
    }
    if(t.size() == 3) {
        bool a = ask2(t[0]);
        if(a) {
            cout << "! " << t[0] << endl;
            fflush(stdout);
            string ss;
            cin >> ss;
            if(ss == ":(") {
                a = ask2(t[1]);
                if(a) {
                    cout << "! " << t[1] << endl;
                    fflush(stdout);
                    string ss;
                    cin >> ss;
                }
                else {
                    cout << "! " << t[2] << endl;
                    fflush(stdout);
                    string ss;
                    cin >> ss;
                }
            }
        }
        else {
            a = ask2(t[0]);
            if(a) {
                cout << "! " << t[0] << endl;
                fflush(stdout);
                string ss;
                cin >> ss;
                if(ss == ":(") {
                    a = ask2(t[1]);
                    if(a) {
                        cout << "! " << t[1] << endl;
                        fflush(stdout);
                        string ss;
                        cin >> ss;
                    }
                    else {
                        cout << "! " << t[2] << endl;
                        fflush(stdout);
                        string ss;
                        cin >> ss;
                    }
                }
            }
            else {
                cout << "! " << t[1] << endl;
                fflush(stdout);
                string ss;
                cin >> ss;
                if(ss == ":(") {
                    cout << "! " << t[2] << endl;
                    fflush(stdout);
                    string ss;
                    cin >> ss;
                }
            }
        }
    }
    else {
        cout << "! " << t[0] << endl;
        fflush(stdout);
        string ss;
        cin >> ss;
        if(ss == ":(") {
            cout << "! " << t[1] << endl;
            fflush(stdout);
            cin >> ss;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}