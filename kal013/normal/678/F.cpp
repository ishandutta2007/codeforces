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
// #define codechef
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ ";
	for(auto v : V) os << v << " ";
	return os << "]";
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
const int maxn=2e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;

inline void read(auto &x) {cin>>x;}




/*/-----------------------------Code begins----------------------------------/*/

struct pt{
    #define F1 ll
    #define F2 ll
    #define F3 ll
    F1 x,y;
    
    pt() {};
    pt(F1 _x): x(_x),y((F1)(0)){};
    pt(F1 _x, F1 _y): x(_x),y(_y){};
    pt operator + (const pt &p) const {return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const {return pt(x-p.x,y-p.y);}
    F2 operator * (const pt &p) const {return x*p.x+y*p.y;}
    F2 operator ^ (const pt &p) const {return x*p.y-y*p.x;}
    pt operator * (const F3 c) const {return pt(x*c,y*c);}
    pt operator / (const F3 c) const {return pt(x/c,y/c);}
    pt operator += (const pt &p) {this->x+=p.x;this->y+=p.y;return *this;}
    pt operator -= (const pt &p) {this->x-=p.x;this->y-=p.y;return *this;}
    pt operator *= (const F3 c) {this->x*=c;this->y*=c; return *this;}
    pt operator /= (const F3 c) {this->x/=c;this->y/=c;return *this;}
    // COMPARES x first
    inline bool operator < (const pt&r) {return (x<r.x || (x==r.x && y<r.y));}
    inline bool operator == (const pt &r) {return (y==r.y && x==r.x);}
    inline bool operator > (const pt &r) {return (x>r.x || (x==r.x && y>r.y));}
    inline bool operator <= (const pt &r) {return !(*this>r);}
    inline bool operator >= (const pt &r) {return !(*this<r);}
    inline bool operator != (const pt &r) {return !(*this==r);}
    friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
    friend ostream& operator << (ostream& os, const pt& p) {return os<<p.x<<" "<<p.y;}
    
    
};

inline int ccw(pt a,pt b,pt c){
    F2 d=((b-a)^(c-a));
    if (d==0) return 0;
    if (d<0) return -1;
    return 1;
}


const int INF=3e18;
struct convex_hull{
    vector<pt> down;
    
    convex_hull() {};
    convex_hull(vector<pt> points){
        build(points);
    }
    inline void clear(){
        down.clear();
    }
    void build(vector<pt> points){
        down=points;
        sort(all(down));
        int n=down.size(),m=0;
        
        For(i,n){
            if (down[i].y==INF && m>0) continue;
            while ((m>0 && down[m-1].y==INF) || (m>1 && ccw(down[m-2],down[m-1],down[i])<=0)) --m;
            
            down[m++]=down[i];
        }
        
        down.resize(m);
    }
    int min(int x){
        pt line={x,1};
        if (down.empty()) return INF;
        int low=0,high=down.size()-1,mid;
        while (low<high){
            mid=(low+high)/2;
            if (down[mid]*line>down[mid+1]*line) low=mid+1;
            else high=mid;
        }
        return down[low]*line;
    }
};



vector<pt> T[maxn];
convex_hull seg[maxn];
#define M (s+e)/2
void update(int node,int s,int e,int l,int r,pt x){
    if (e<l || s>r) return;
    if (l<=s && e<=r) {T[node].pb(x);return;}
    update(2*node,s,M,l,r,x);update(2*node+1,M+1,e,l,r,x);
}

int query(int node,int s,int e,int l,int x){
    int ans=seg[node].min(x);
    if (s==e) return ans;
    if (l<=M) return min(ans,query(2*node,s,M,l,x));
    return min(ans,query(2*node+1,M+1,e,l,x));
}

void build(int node,int s,int e){
    seg[node]=convex_hull(T[node]);
    T[node].clear();
    if (s!=e){
        build(2*node,s,M);build(2*node+1,M+1,e);
    }
}

struct q{
    int t,l,r;
    friend istream& operator >> (istream& is, q& p){
        is>>p.t;
        if (p.t==1) return is>>p.l>>p.r;
        else return is>>p.l;
    }
};

q Q[maxn];
void solve(){
    int n;
    read(n);
    For(i,n){
        read(Q[i]);
        if (Q[i].t==2) {
            int x=Q[i].l-1;
            update(1,0,n-1,x,i-1,pt(-Q[x].l,-Q[x].r));
            Q[x].t=2;
        }
    }
    For(i,n){
        if (Q[i].t==1) update(1,0,n-1,i,n-1,pt(-Q[i].l,-Q[i].r));
    }
    build(1,0,n-1);
    
    For(i,n){
        if (Q[i].t==3){
            int x=query(1,0,n-1,i,Q[i].l);
            if (x==INF) d1("EMPTY SET");
            else d1(-x);
        }
    }
    
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