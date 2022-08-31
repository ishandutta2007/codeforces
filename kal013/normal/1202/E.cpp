/*/ Author: kal013 /*/
#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
typedef priority_queue<ppi,vppi,greater<ppi>> min_heap_ppi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define tern(a,b,c) (!!(a))*b+(!(a))*c
#define cross(i,a,b) ((tern(b>a,1,-1))*(i))>=((tern(b>a,1,-1))*(b))
#define loop(i,a,b) for(int i=a;i!=b;i+=tern(b>a,1,-1))
#define sloop(i,a,b,s) for(int i=a;(!(cross(i,a,b)));i+=s)
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()
#define ll long long
//#define file cin
//#define codechef
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ ";
	for(auto v : V) os << v << " ";
	return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
	os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');
		cerr.write(names, comma - names) << " : " << arg1<<" | ";
		__f(comma+1, args...);
	}
#else
	#define trace(...)
#endif
const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
#endif
#ifdef codechef
inline void read(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}
inline void read_str(char *str){
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
#else
inline void read(int &x) {cin>>x;}
#endif
inline int fast_expo(int base,int power,int modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    // int tmp=ans;
    return ans;
}

inline int fib(int n,int a=1,int b=1,int c=1,int d=0,int acca=0,int accb=1,int m=mod){
    if (n==0) return acca;

    if (n&1) return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,((a*acca)%m+(b*accb)%m)%m,((c*acca)%m+(d*accb)%m)%m,m);
    else return fib(n/2,((a*a)%m+(b*c)%m)%m,((a*b)%m+(b*d)%m)%m,(c*(a+d)%m)%m,((c*b)%m+(d*d)%m)%m,acca,accb,m);
}

/*/-----------------------------Code begins----------------------------------/*/




struct suffix_array{
    // Karkkainen implementation from paper https://www.cs.helsinki.fi/u/tpkarkka/publications/icalp03.pdf
    vi p,cnt,s,lcp;
    int n;
    int alphabet;
    char start;
    string text;
    suffix_array(int a=256,char st='a'): alphabet(a),start(st){}

    inline bool leq(int a1, int a2, int b1, int b2) {return (a1 < b1 || (a1 == b1 && a2 <= b2));}
    inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));}

    void radix(int* A,int* B,int* R,int N,int K){
        int* C=new int[K+1];
        for (int i = 0; i <= K; ++i) C[i] = 0;
        for (int i = 0; i < N; ++i) ++C[R[A[i]]]; 
        for (int i = 0, sum = 0; i <= K; ++i)  {int t = C[i]; C[i] = sum; sum += t;}
        for (int i = 0; i < N; i++) B[C[R[A[i]]]++] = A[i]; 
        delete [] C;
    }

    void suffixArray(int* s, int* SA, int N, int K) {
        int n0=(N+2)/3, n1=(N+1)/3, n2=N/3, n02=n0+n2;
        int* s12 = new int[n02 + 3]; s12[n02]= s12[n02+1]= s12[n02+2]=0;
        int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
        int* s0 = new int[n0];
        int* SA0 = new int[n0];
        for (int i=0, j=0; i < N+(n0-n1); i++) if (i%3 != 0) s12[j++] = i;
        radix(s12 , SA12, s+2, n02, K);
        radix(SA12, s12 , s+1, n02, K);
        radix(s12 , SA12, s , n02, K);
        int name = 0, c0 = -1, c1 = -1, c2 = -1;
        for (int i = 0; i < n02; i++) {
            if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2)
            {name++; c0 = s[SA12[i]]; c1 = s[SA12[i]+1]; c2 = s[SA12[i]+2]; }
            if (SA12[i] % 3 == 1) { s12[SA12[i]/3] = name; } 
            else {s12[SA12[i]/3 + n0] = name; }
        }
        if (name < n02) {
            suffixArray(s12, SA12, n02, name);
            for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
        } 
        else for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
        for (int i=0, j=0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
        radix(s0, SA0, s, n0, K);
        for (int p=0, t=n0-n1, k=0; k < N; k++) {
            #define GetI() (SA12[t] < n0 ? SA12[t]*3+1: (SA12[t] - n0) * 3 + 2)
            int i = GetI();
            int j = SA0[p]; 
            if (SA12[t] < n0 ?leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0])){
                SA[k] = i; t++;
                if (t == n02) for (k++; p < n0; p++, k++) SA[k] = SA0[p];
            } 
            else {
                SA[k] = j; p++;
                if (p == n0) for (k++; t < n02; t++, k++) SA[k] = GetI();
            }

        }
        #undef GetI
        delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
    }
    void build(string t){
        n=t.size();
        text=t+"$";
        int* S=new int[n+3];
        s.resize(n+1);
        for(int i=0;i<n;++i) {S[i]=(int)(t[i]-start)+1;s[i]=S[i];}
        for(int i=n;i<=n+2;++i) S[i]=0;
        int* P=new int[n+3];
        suffixArray(S,P,n,alphabet);
        ++n;
        p.resize(n);
        cnt.assign(max(alphabet,n),0);
        p[0]=n-1;
        for(int i=1;i<n;++i) p[i]=P[i-1];
        delete [] S; delete [] P;
    }
    void prefix(){
        For(i,n) cnt[p[i]]=i;
        lcp.resize(n);
        int len=0;
        For(i,n){
            if (cnt[i]==n-1) {len=0;continue;}
            int j=p[cnt[i]+1];
            while (i+len<n && j+len<n && s[i+len]==s[j+len])++len;
            lcp[cnt[i]]=len;
            if (len) --len;
        }
    }
    // void pre(){
    //     log_2.resize(n+2,0);
    //     For(i,n) dp[0][i]=p[i];
    //     For(i,dp.size()-1){
    //         For(j,n) dp[i+1][j]=(j+(1<<i)<n)?min(dp[i][j],dp[i][j+(1<<i)]):dp[i][j];
    //     }
    //     log_2[1]=0;
    //     for(int i=2;i<=n;++i) log_2[i]=log_2[i/2]+1;
    // }
    // int rmq(int i,int j){
    //     if (i>j) swap(i,j);
    //     int d=log_2[j-i+1];
        
    //     return min(dp[d][i],dp[d][j-(1<<d)+1]);
    // }
    
    pii occur(string pattern){
        int m=pattern.size();
        
        int low=0,high=n-1,l=0,r=n-1;
        For(i,m){
            while (low<n && n-p[low]<=i) low++;
            while (high>=0 && n-p[high]<=i) high--;
            if (high<low) return {-1,-1};
            l=high+1,r=high;
            while (low<=high){
                int mid=(low+high)/2;
                if (text[p[mid]+i]>pattern[i]){
                    high=mid-1;
                }
                else if (text[p[mid]+i]<pattern[i]){
                    low=mid+1;
                }
                else{
                    l=min(l,mid);
                    high=mid-1;
                }
            }
            low=l;
            high=r;
            if (low>high) return {-1,-1};
            r=l;
            while (low<=high){
                int mid=(low+high)/2;
                if (text[p[mid]+i]>pattern[i]){
                    high=mid-1;
                }
                else if (text[p[mid]+i]<pattern[i]){
                    low=mid+1;
                }
                else{
                    r=max(r,mid);
                    low=mid+1;
                }
            }
            if (r<l) return {-1,-1};
            low=l;high=r;
        }
        return {l,r};
    }


};
int seg[4*MaxN];

int prf[2*MaxN];

const int SZ=300;

string s[2*MaxN];
pii pos[2*MaxN];

vpi adder[2*MaxN];
int st[2*MaxN],ed[2*MaxN];
void solve(){
    string t;
    cin>>t;
    int n;
    int ans=0;
    cin>>n;
    For(i,n){
        cin>>s[i];
    }
    suffix_array U(26,'a');
    U.build(t);
    U.prefix();
    // trace(U.text,U.p,U.lcp);
    vector<pair<int,pii>> biger;
    For(i,n){
        pos[i]=U.occur(s[i]);
        int len=s[i].size();
        if (pos[i].F>pos[i].S || pos[i].F==-1 || pos[i].S==-1) continue;
        int l=pos[i].F,r=pos[i].S;
        if (len<SZ){
            adder[len].pb({l,r});
        }
        else{
            biger.pb({len,{l,r}});
        }
    }
    int M=t.size()+1;
    sort(all(biger));
    for(int len=1;len<SZ;++len){
        for(auto x:adder[len]){
            ++prf[x.F];
            --prf[x.S+1];
            // trace(x.F,x.S,len);
        }
        For(i,M-1) prf[i+1]+=prf[i];
        for(int i=1;i<M;++i){
            int jj=U.p[i]+len;
            // trace(st[jj],jj,U.lcp[i],ed[U.lcp[i]],len,i);
            ans+=st[jj]*prf[i];
            ans+=prf[i]*ed[U.p[i]];
            ed[jj]+=prf[i];
            st[U.p[i]]+=prf[i];
            // trace(prf[i],i,ans,len,U.p[i]);
            
        }
        // for(int i=1;i<M;++i){
        //     int jj=U.p[i]+len;
            
        // }
        // trace(len,ans);
        For(i,M) {
            prf[i]=0;
            // trace(i,len,st[i],ed[i]);
        }
    }
    for(auto x:biger){
        int l=x.S.F,r=x.S.S,len=x.F;
        for(int i=l;i<=r;++i){
            int jj=U.p[i]+len;
            ans+=st[jj];
            ans+=ed[U.p[i]];
            ++ed[jj];
            ++st[U.p[i]];
        }
        // for(int i=l;i<=r;++i){
        //     int jj=U.p[i]+len;
            
        // }
    }
    d1(ans);

}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    // #define LOCAL
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    fio;
    
    int t=1;
    // read(t);
    while(t--) {
        solve();
    }
}