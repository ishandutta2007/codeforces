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
template<typename T> void cmin(T& a, T b) {a = min(a,b);}

typedef array<int,2> ar2;
struct mypq {
    vector<ar2> ts;
    int k=0;
    void push(int t, int i) {ts.push_back({t,i});}
    void precomp() { sort(all(ts)); }
    int size() {return ts.size();}
    void reset() { k=0; }
    bool empty(){ return k==ts.size();}
    ar2 min() { return ts[k]; }
    void rollback() { k--; }
    ar2 pop() {return ts[k++]; }
};

int main() {
    mypq pq[2][2];

    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=n;++i) {
        int t,a,b; cin >> t >> a >> b;
        pq[a][b].push(t,i);
    }
    for(int i : {0,1}) for(int j : {0,1}) {
        if(i+j!=2) pq[i][j].push(oo,-1);
        pq[i][j].precomp();
    }

    ll cur=0;
    int as=min(m,pq[1][1].size()),bs=as;
    int num=as;
    for(int i=0;i<as;++i) {
        cur+=pq[1][1].ts[i][0];
    }

    auto step = [&]() {
        num++;
        if(as<k) {
            as++;
            return pq[1][0].pop();;
        }
        if(bs<k) {
            bs++;
            return pq[0][1].pop();;
        }
        tuple<array<int,2>,bool,bool> got = {{oo,-1},0,0};
        for(int i : {0,1}) for(int j : {0,1}) {
            if(i+j==2) continue;
            cmin(got,{pq[i][j].min(),i,j});
        }
        auto [el,a,b] = got;
        pq[a][b].pop();
        as+=a,bs+=b;
        return el;
    };
    pair<ll,int> ans={1e18,-1};
    for(int i=as;i>=0;--i) {
        // Loop over all possible amounts of (1,1)'s in decreasing order
        while(true) {
            while(num<m) {
                auto el = step();
                if(el[0]==oo) goto answering;
                cur+=el[0];
            }
            if(as>=k and bs>=k) {
                ans = min(ans,{cur,i});
                break;
            } else {
                if(pq[0][0].k!=0) 
                    pq[0][0].rollback(), cur-=pq[0][0].min()[0], num--;
                else break;
            }
        }
        if(i) {
            cur-=pq[1][1].ts[i-1][0];
            num--,as--,bs--;
        }
    }
    answering:
    if(ans.second==-1) cout << "-1\n";
    else { 
        cout << ans.first << '\n';
        // resimulate for answer
        for(int i : {0,1}) for(int j : {0,1}) pq[i][j].reset();
        int boths = ans.second;
        vi st; for(int i=0;i<boths;++i) st.push_back(pq[1][1].ts[i][1]);
        as=boths,bs=as,num=as;
        while(num<m) {
            st.push_back(step()[1]);
        }
        cout << st << '\n';
    }


}