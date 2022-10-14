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
const int sigma = 26, mask = sigma-1;
const char firstc = 'a';
struct ahocorasick {
struct smallmap {
    int ar[sigma]={};
    int get(char to) {
        return ar[to-firstc];
    }
    void add(char to, int id) {
        ar[to-firstc] = id;
    }
};

int p=2;
vector<smallmap> trie = {{},{}};
vi fail,cnt={0,0};
vector<bool> marked = {0,0};
void addword(const string& s) {
    int at = 1;
    auto c=s.begin();
    while(c!=s.end()) {
        int tmp;
        if(!(tmp = trie[at].get(*c))) {
            trie[at].add(*c, p);
            trie.push_back(smallmap());
            marked.push_back(0);
            cnt.push_back(0);
            at = p++;
        } else {
            at = tmp;
        }
        c++;
    }
    cnt[at]=1;
    marked[at]=true;
}
queue<int> q;

int transition(int at, char c) {
    int tmp;
    while( (tmp = trie[at].get(c))==0) {
        at = fail[at];
    } 
    return tmp;
}
void makefail(int at, char c, int to) {
    while(true) {
        at = fail[at];
        int ans = trie[at].get(c);
        if(ans) {
            fail[to] = ans;
            cnt[to] += cnt[ans];
            break;
        }
    }
    q.push(to);
}

void update(int at) {
    for(int d=firstc;d<firstc+sigma;++d) {
        int to = trie[at].get(d);
        if(to) {
            makefail(at,d,to);
        }
    }
}

void construct() {
    // construct fail array
    bool doupdate[firstc+sigma]={};
    fail.resize(p);
    fail[1] = 1;
    int tmp;


    for(int c = firstc;c<firstc+sigma;++c) {
        if(!(tmp = trie[1].get(c))) {
            trie[1].add(c,1);
        } else {
            doupdate[c] = true;
            fail[tmp]=1;
        }
    }
    for(int c = firstc;c<firstc+sigma;++c) {
        if(doupdate[c]) {
            tmp = trie[1].get(c);
            update(tmp);
        }
    }
    while(!q.empty()) {
        update(q.front()); q.pop();
    }
}
};
struct dynamicAho {
    vector<ahocorasick> ahos;
    vector<list<string>> sets;
    void add(const string& s) {
        list<string> cur = {s};
        while(!sets.empty() and cur.size()==sets.back().size()) {
            cur.splice(cur.end(),sets.back());
            sets.pop_back();
            ahos.pop_back();
        }
        sets.push_back(cur);
        ahos.push_back({});
        for(auto& t : sets.back()) {
            ahos.back().addword(t);
        }
        ahos.back().construct();

    }
    ll occ(const string& s) {
        ll ans=0;
        for(auto& a : ahos) {
            int at=1;
            for(auto c : s) {
                at = a.transition(at,c);
                ans+=a.cnt[at];
            }
        }
        return ans;
    }
};
int main() {
    dynamicAho ins, del;
    int m; cin >> m;
    while(m--) {
        int t; cin >> t;
        string s; cin >> s;
        if(t==1) ins.add(s);
        else if(t==2) del.add(s);
        else {
            cout << ins.occ(s)-del.occ(s) << endl;
        }
    }

}