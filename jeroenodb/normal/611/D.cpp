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
const int mxN = 5000+1, oo = 1e9;
const long long MOD = 1e9+7;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
mint h[mxN];
const mint base = 12345;
mint dp[mxN][mxN], pref[mxN][mxN], pw[mxN];
typedef array<int,3> ar3;
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixsort(int *a, int *b, int *r, int n, int K) {
    static int c[mxN+1];
    fill(c,c+K+1,0);
    for (int i = 0; i < n; i++)
        c[r[a[i]]+1]++;
    for (int i = 1; i <= K; i++) 
    {
        c[i]+=c[i-1];
    }
    for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
}
// find the suffix array SA of s[0..n-1] in {1..K}n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
// uses 1+1+4/3+4/9+4/27+... = 4n ints auxiliary storage, (besides the Suffix Array itself)
void suffixArray(int *s, int *SA, int n, int K) {
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    int *s12 = new int[n02 + 3];
    s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
    int *SA12 = new int[n02 + 3];
    SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
    for (int i = 0, j = 0; i < n + (n0 - n1); i++)
        if (i % 3 != 0)
            s12[j++] = i;
    radixsort(s12, SA12, s + 2, n02, K);
    radixsort(SA12, s12, s + 1, n02, K);
    radixsort(s12, SA12, s, n02, K);
    int name = 0;
    ar3 c = {-1, -1, -1};
    for (int i = 0; i < n02; i++) {
        ar3 newc = {s[SA12[i]], s[SA12[i] + 1],  s[SA12[i] + 2]};
        if (newc != c) {
            name++;
            c = newc;
        }
        s12[SA12[i] / 3 + (SA12[i] % 3 == 2?n0:0)] = name;
    }
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
    int *SA0 = new int[n0];
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0)
            SA[j++] = 3 * SA12[i]; 
    radixsort(SA, SA0, s, n0, K);
    for(int t=n0-n1;t<n02;++t) 
        SA12[t]=(SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    auto comp = [&](int i, int j) { 
        bool flip=false;
        if(i%3==0) {
            swap(i,j);
            flip=true;
        }
        bool smaller =  (i%3==1 ? pi{s[i], s12[i/3 + n0]} <= pi{s[j], s12[j/3]}
            : ar3{s[i], s[i + 1], s12[i/3 + 1]} <= ar3{s[j], s[j + 1], s12[j / 3 + n0]});
        return smaller!=flip;
    };
    merge(SA12+n0-n1,SA12+n02,SA0,SA0+n0,SA,comp);
    delete[] s12;
    delete[] SA12;
    delete[] SA0;
}
vi suffixArray(const string& s) {
    int n = s.size();
    int* SA = new int[n];
    int* S = new int[n+3];
    S[n]=S[n+1]=S[n+2]=0;
    for(int i=0;i<n;++i) S[i] = s[i];
    suffixArray(S,SA,n,256);
    vi res;
    move(SA,SA+n,back_inserter(res));
    return res;
}
vector<int> kasai(string& s, vector<int>& sa) {
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);

    for(int i=0; i<n; i++) rank[sa[i]]=i;

    for(int i=0; i<n; i++, k?k--:0) {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}
mint get(int i, int j) {
    return h[j+1]-pw[j-i+1]*h[i];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    pw[0]=1;
    for(int i=1;i<=n;++i) {
        h[i] = base*h[i-1]+int(s[i-1]);
        pw[i]=base*pw[i-1];
    }
    s.push_back('0'-1);
    auto sa = suffixArray(s);
    vi rank(n+2);
    for(int i=0;i<=n;++i) rank[sa[i]]=i;
    for(int i=0;i<n;++i) {
        for(int j=1;j<=n;++j) {
            if(j<=i+1 and s[i-j+1]!='0') {
                if(j==i+1) dp[i][j]=1;
                else {
                    dp[i][j]=pref[i-j][j-1];
                    // bin search?
                    int ssa=i-2*j+1,ssb=i-j+1;
                    if(rank[ssa]<rank[ssb] and !(get(ssa,ssa+j-1)==get(ssb,ssb+j-1))) {
                        dp[i][j]+=dp[i-j][j];
                    }
                }
            }
            // if(dp[i][j].d>0) {
            //     cerr << s.substr(i-j+1,j) << '\n';
            // }
            pref[i][j]=dp[i][j]+pref[i][j-1];

            // prefix sums
        }
    }
    cout << pref[n-1][n].d << '\n';
}