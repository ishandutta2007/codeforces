/*/ Author: kal013 /*/
#include <bits/stdc++.h>
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
inline void read(auto &x) {cin>>x;}
#endif
inline int fast_expo(int base,int power,int modulo=mod){
    base%=mod;
    if (base<0) base+=mod;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
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
    vi p,c,cnt,s,lcp,freq,log_2;
    vector<vi> dp;
    int n;
    string text;
    int alphabet;
    char start;
    suffix_array(int a=256,char st='a'): alphabet(a),start(st){}
    void build(string t){
        n=t.size()+1;
        text=t+"$";
        s.resize(n,0);p.resize(n);c.resize(n);cnt.assign(max(alphabet,n),0);
        For(i,n-1) {s[i]=(int)(t[i]-start)+1;cnt[s[i]]++;}
        cnt[0]++;
        vi pn(n),cn(n);
        For(i,cnt.size()-1) cnt[i+1]+=cnt[i];
        For(i,n) p[--cnt[s[i]]]=i;
        int classes=0;
        c[p[0]]=classes;
        For(i,n-1) c[p[i+1]]=(s[p[i+1]]!=s[p[i]])?(++classes):classes;
        for(int k=1;k<=(n);k<<=1){
            dp.pb(vi(n));
            For(i,n) pn[i]=(p[i]-k<0)?p[i]-k+n:p[i]-k;
            fill(cnt.begin(),cnt.begin()+classes+1,0);
            For(i,n) cnt[c[pn[i]]]++;
            For(i,classes) cnt[i+1]+=cnt[i];
            Rev(i,n) p[--cnt[c[pn[i]]]]=pn[i];
            classes=0;
            cn[p[0]]=classes;
            For(i,n-1) cn[p[i+1]]=(c[p[i]]!=c[p[i+1]] || c[(p[i]+k)%n]!=c[(p[i+1]+k)%n])?++classes:classes;
            c.swap(cn);
        }
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
    void pre(){
        log_2.resize(n+2,0);
        For(i,n) dp[0][i]=p[i];
        For(i,dp.size()-1){
            For(j,n) dp[i+1][j]=(j+(1<<i)<n)?min(dp[i][j],dp[i][j+(1<<i)]):dp[i][j];
        }
        log_2[1]=0;
        for(int i=2;i<=n;++i) log_2[i]=log_2[i/2]+1;
    }
    int rmq(int i,int j){
        if (i>j) swap(i,j);
        int d=log_2[j-i+1];
        
        return min(dp[d][i],dp[d][j-(1<<d)+1]);
    }
    
    vi first_occur(string pattern){
        int m=pattern.size();
        vi fir(m,n);
        int low=0,high=n-1,l=0,r=n-1;
        For(i,m){
            while (low<n && n-p[low]<=i) low++;
            while (high>=0 && n-p[high]<=i) high--;
            if (high<low) break;
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
            if (low>high) break;
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
            if (r<l) break;
            fir[i]=rmq(l,r);
            low=l;high=r;
        }
        return fir;
    }
    
};

void solve(){
    string t,b;
    cin>>t;
    string s;
    Rev(i,t.size()) s+=t[i];
    int l;
    read(l);
    suffix_array U(26,'A'),u(26,'A');
    U.build(t);
    U.prefix();
    U.pre();
    u.build(s);
    u.prefix();
    u.pre();
    int n=t.size();
    int ctr=0;
    For(i,l){
        cin>>t;
        vi fi=U.first_occur(t);
        reverse(all(t));
        vi las=u.first_occur(t);
        int m=fi.size();
        if (m==1) continue;
        // if (fi[m-1]<n) {ctr++;continue;}
        For(i,m-1){
            if (fi[i]+m-1<=(n-las[m-2-i]-1)) {ctr++;break;}
        }
    }
    d1(ctr);
    // for(int i=1;i<=l;++i){
    //     d0(((i>min(t.size(),b.size()))?0:U.freq[i]));
    // }
    // d1("")
    
    // read(q);
    // For(_,q){
    //     read(fi);
    //     d1(((fi>t.size())?0:U.freq[fi]));
    // }
    
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    fio;
    int t=1;
    // read(t);
    while(t--) {
        solve();
    }
}