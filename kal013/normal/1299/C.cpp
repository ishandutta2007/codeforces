/*/ Author: kal013 /*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
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
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

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
inline int inv(int base,int modulo=mod){
    return fast_expo(base,modulo-2,modulo);
}


/*/-----------------------------Code begins----------------------------------/*/


#define ld long double
//atan2(y,x) slope of line (0,0)->(x,y) in radian (-PI,PI]
// to convert to degree multiply by 180/PI
ld INF = 1e30;
ld EPS = 1e-8;
inline bool eq(ld a,ld b){return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b){return a+EPS<b;}
inline bool gt(ld a,ld b){return a>b+EPS;}
inline bool le(ld a,ld b){return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b){return gt(a,b)||eq(a,b);}
struct pt{
		#define F1 ld
		#define F2 ld
		#define F3 ld
		F1 x,y; pt() {};
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
		// COMPARES y first
		bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
		inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
		bool operator > (const pt &p) const{ return p<pt(x,y);}
		inline bool operator <= (const pt &r) const {return !(*this>r);}
		inline bool operator >= (const pt &r) const {return !(*this<r);}
		inline bool operator != (const pt &r) const {return !(*this==r);}
		friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
		friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
};
ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}

ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}
int orient(pt a,pt b,pt c){ pt p=b-a,q=c-b; 
	double cr=cross(p,q); if(eq(cr,0))return 0;
	if(lt(cr,0))return 1; return -1;}





  
inline bool cmp_x(pt a,pt b){
	return (lt(a.x,b.x) || (eq(a.x,b.x) && lt(a.y,b.y)));
}
inline int ccw(pt a,pt b,pt c){
	F2 d=((b-a)^(c-a));
	if (eq(d,0)) return 0;   if (lt(d,0)) return -1;
	return 1;
}
// const ll INF=1e18;
struct convex_hull{
	vector<pt> down; // vector<pt> up;
	vector<int> idx;
	int n=0;
	int tot=0;
	int plo,phi;
	int clo;
	convex_hull(): n(0ll) {};
	convex_hull(vector<pt> points,bool issort=false){
		down=points;
		if(!issort)sort(all(down),cmp_x);n=down.size();
		// up.resize(n);  For(i,n) up[i]=down[i];
		build();
	}
	convex_hull operator = (const convex_hull& a){
		down=a.down;n=down.size(); // up=a.up;
		return *this;
	}
	void build(){
		int m=0; if (n<=1){ return; }
		For(i,n){ while (m>1 && ccw(down[m-2],down[m-1],down[i])<=0) --m;
			down[m++]=down[i]; }
		down.resize(m);
		// m=0; //convert cht to convex hull
		// For(i,n){ while(m>1 && ccw(up[m-2],up[m-1],up[i])>=0) --m;
		//	 up[m++]=up[i]; }
		// up.resize(m);
		n=m;
	}

	void Add(pt X){
		++tot;
		n=down.size();
		while(n>1 && ccw(down[n-2],down[n-1],X)<=0) {--n;down.pop_back();idx.pop_back();}
		down.pb(X);
		idx.pb(tot);
		++n;

	}
	void clear(){ down.clear();n=0;/*up.clear();*/ }
	convex_hull merger(const convex_hull& a) const {
		vector<pt> points(a.down.size()+down.size());
		merge(down.begin(),down.end(),a.down.begin(),a.down.end(),points.begin());
		convex_hull b(points,true); return b; }
	// vector<pt> All(){
	// 	vector<pt> cu=down; for(int i=(int)up.size()-2;i>0;--i) cu.pb(up[i]);
	// 	return cu; }
	pair<ld,ll> min(ld x){
		if (n==0) return {INF,-1}; 

		int low=plo,high=phi;
		assert(low<=high);
		pt line={x,1};
		while (low<high){ 
			int mid=(low+high)/2;
			if(lt(down[mid]*line,down[mid+1]*line)) high=mid; 
			else low=mid+1;
		} 
		clo=low;
		return {down[low]*line,idx[low]}; }
	friend ostream& operator<<(ostream& os,const convex_hull& p){return os<<"{"<<p.n<<" : "<<p.down<<"}";}
};



int apnxt[maxn];
int A[maxn];

int pref[maxn];

bool does[maxn];

bool Lt(pair<ld,int> p1,pair<ld,int> p2){
	if (eq(p1.F,p2.F)) return p1.S<p2.S;
	return lt(p1.F,p2.F);
}

inline ll read() 
{
    ll n = 0;
    char c = getchar();
    while (!('0' <= c && c <= '9')) 
    {
        c = getchar();
    }
    while ('0' <= c && c <= '9') 
    {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n;
}
const ld EPS2=1e-5;


void solve(){
	int n;
	n=read();
	Rep(i,n) 
	{
		A[i]=read();
		pref[i]=pref[i-1]+A[i];
	}
	int mn=A[n];

	convex_hull U;
	for(int i=1;i<=n;){
		does[i]=1;
		int j=i+1;
		while(j<=n && A[j]<A[j-1]) {does[j]=0;++j;}
		i=j;
	}
	for(int i=n;i>=1;--i){
		U.Add(pt(-i,pref[i]));
		mn=min(mn,A[i]);
		// if (!does[i]) {apnxt[i]=i;continue;}

		ld lo=mn,hi=A[i];

		pair<ld,int> ans={A[i],(i)};
		ld prlo=0,prhi=0;


		int t1=0,t2=U.n-1;
		while((lo+EPS2<hi && t1<t2)){
			if (eq(prlo,lo) && eq(prhi,hi)) break;
			ld mid=(lo+hi)/((ld)2.0);
			prlo=lo;
			prhi=hi;
			U.plo=t1;
			U.phi=t2;
			pair<ld,int> tp=U.min(mid);
			ld z1=pref[i-1]-mid*(i-1)-tp.F;


			// trace(U.clo,mid,lo,hi);
			if (ge(z1,0)){
				ans={mid,n+1-tp.S};
				hi=mid;


				ld s1=pref[ans.S]-pref[i-1];
				s1/=((ld)(ans.S-i+1));
				hi=min(hi,s1);
				ans.F=hi;

				t1=max(t1,U.clo);

			}
			else{
				lo=mid;
				t2=min(t2,U.clo);

			}
		}
		// trace(ans);
		int nx=ans.S;
		apnxt[i]=nx;
	}

	for(int i=1;i<=n;){
		int j=apnxt[i];
		int su=pref[j]-pref[i-1];
		ld res=((ld)su)/((ld)(j-i+1));
		for(int k=i;k<=j;++k){
			cout<<res<<" ";
		}


		i=j+1;
	}
	cout<<endl;


}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   	cout<<fixed<<setprecision(10);
   	// cerr<<fixed<<setprecision(10);
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}