#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int ch(char c) {return c-'a';}
typedef array<int,26> CNT;

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    if(n%k!=0) {
        cout << "-1\n";
        return;
    }
    // it's possible
    // greedy
    int left=n;
    
    vector<CNT> nxtbigger(n+1); // data structure for checking if string s is too big here.
    fill(all(nxtbigger[n]),n);
    auto nxtsmaller = nxtbigger;
    for(int i=n-1;i>=0;--i) {
        int id = ch(s[i]);
        nxtbigger[i]=nxtbigger[i+1];
        nxtsmaller[i] = nxtsmaller[i+1];
        for(int j=0;j<id;++j) nxtbigger[i][j] = i;
        for(int j=id+1;j<26;++j) nxtsmaller[i][j]=i;
    }
    string res(n,'?');
    CNT cnt  ={};
    bool issmall=true;
    for(int i=0;i<n;++i) {
        auto c = issmall?s[i]:'a';
        int id = ch(c);
        auto make = [&]() {
            if(!cnt[id]) 
                cnt[id] = k, left-=k;
            cnt[id]--;
        };
        auto undo = [&]() {
            cnt[id]++;
            if(cnt[id]==k) 
                cnt[id]-=k, left+=k;
        };
        auto isgood = [&]() {
            if(!cnt[id] and !left) return false;
            if(!issmall or c=='z') return true;
            make();
            cnt[25]+=left;
            int l = i+1;
            bool bad=false;
            for(int j=25;j>=0;--j) {
                int r = l+cnt[j];
                if(nxtsmaller[l][j]<min(r,nxtbigger[l][j])) {
                    break;
                }
                if(nxtbigger[l][j]<r) {
                    bad =true;
                    break;
                }
                l=r;
            }
            cnt[25]-=left;
            undo();
            return !bad;
        };
        for(;;c++,id++,issmall=false) {
            if(isgood()) 
                break;
        }
        make();
        res[i]=c;
    }
    cout << res << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}