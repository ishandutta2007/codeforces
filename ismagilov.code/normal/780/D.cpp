#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd ; exit(0)
#define double long double

using namespace std;


int m;


map<string, map<char, int> > gg;

map<int, string> dd;
map<int, string> dd1;
map<int, string> nuu;
set<string> used;
set<string> used1;
set<string> nu;
set<int> usedd;
set<int> usedd1;
set<int> nuuu;

map<string, vector<int> > ggg;

vector<pr<pr<string, string>, int> > lenn;

void dfs(int i, bool pr){
    if (pr){
        used1.insert(lenn[i].fs.sc);
        dd1[lenn[i].sc] = lenn[i].fs.sc;
        for (auto to : ggg[lenn[i].fs.sc]){
            if (dd1.find(lenn[to].sc) == dd1.end() && dd.find(lenn[to].sc) == dd.end())
            if (lenn[to].fs.fs == lenn[i].fs.sc){
                dfs(to, 1);
            }
            else{
                dfs(to, 0);
            }
        }
    }
    else{
        used1.insert(lenn[i].fs.fs);
        dd1[lenn[i].sc] = lenn[i].fs.fs;
        for (auto to : ggg[lenn[i].fs.fs]){
            if (dd1.find(lenn[to].sc) == dd1.end() && dd.find(lenn[to].sc) == dd.end())
            if (lenn[to].fs.fs == lenn[i].fs.fs){
                dfs(to, 1);
            }
            else{
                dfs(to, 0);
            }
        }
    }
}

void ddfs(string v){
    if (len(gg[v]) == 1){
        string s = "";
        s.pb(v[0]);
        s.pb(v[1]);
        char c;
        int kon;
        for (auto to : gg[v]){
            c = to.fs;
            kon = to.sc;
        }
        s.pb(c);
        lenn.pb(mp(mp(v, s), kon));
        ggg[v].pb(len(lenn) - 1);
        ggg[s].pb(len(lenn) - 1);
    }
    else{
        for (auto to : gg[v]){
            string s = "";
            s.pb(v[0]);
            s.pb(v[1]);
            s.pb(to.fs);
            used.insert(s);
            dd[to.sc] = s;
        }
    }
}



main() {
	//freopen("kek.in", "r", stdin);
	//freopen("kek.out", "w", stdout);
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        string st = "";
        for (int i = 0; i < 3; i++){
            st.pb(a[i]);
        }
        if (gg[st].find(b[0]) != gg[st].end()){
            cout << "NO" << endl;
            return 0;
        }
        gg[st][b[0]] = i;
    }
    for (auto v : gg){
        ddfs(v.fs);
    }
    m = len(lenn);
    for (int i = 0; i < m; i++){
        if (dd.find(lenn[i].sc) == dd.end()){
            bool prav = 1;
            used1 = nu;
            dd1 = nuu;
            dfs(i, 0);
            for (auto g : used1){
                if (used.find(g) != used.end()){
                    prav = 0;
                }
            }
            if (len(used1) == len(dd1) && prav){
                for (auto d : used1){
                    used.insert(d);
                }
                for (auto d : dd1){
                    dd[d.fs] = d.sc;
                }
            }
            else{
                bool prav = 1;
                used1 = nu;
                dd1 = nuu;
                dfs(i, 1);
                for (auto g : used1){
                    if (used.find(g) != used.end()){
                        prav = 0;
                    }
                }
                if (len(used1) == len(dd1) && prav){
                    for (auto d : used1){
                        used.insert(d);
                    }
                    for (auto d : dd1){
                        dd[d.fs] = d.sc;
                    }
                }
                else{
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if (len(used) == n && len(dd) == n){
        cout << "YES" << endl;
        for (auto v : dd){
            cout << v.sc << endl;
        }
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
}