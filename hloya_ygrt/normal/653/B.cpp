#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ll long long

const int maxn = 2e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

vector<pair<string,char> > can;
int ans = 0;
map<string,int> was;

    int n, q;
int dfs(string & s)
{
    if (was.find(s) != was.end()){
        return was[s];
    }
    if (s.size() == n)
        return was[s] = 1;

    char f = s.back();
    int cur = 0;
    for (int i=0;i<can.size();i++){
        if (can[i].s == f){
            s.pop_back();
            s.pb(can[i].f.back());
            s.pb(can[i].f.front());
            cur += dfs(s);
            s.pop_back();
            s.pop_back();
            s.pb(f);
        }
    }
    return was[s] = cur;
}

int main()
{
    fast_io;
    //files1;
    cin >> n >> q;
    for (int i=0;i<q;i++){
        string f;
        char t;
        cin >> f >> t;
        can.pb(mp(f,t));
    }
    string s = "a";
    ans = dfs(s);
    cout<<ans;
    return 0;
}