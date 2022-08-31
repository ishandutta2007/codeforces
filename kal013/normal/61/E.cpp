#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream&os, vector<T> V){
	os << "[ ";
	for(auto v : V) os << v << " ";
	return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
	os << "{ ";
	for(auto s : S) os << s << " ";
	return os << "}";
}
template<class L , class R> ostream& operator<<(ostream &os , pair<L, R> P){
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L , class R> ostream& operator<<(ostream &os, map<L, R> M){
	os << "{ ";
	for(auto m : M) os << "(" << m.F << ":" << m.S << ")";
	return os << "}";
}
#define cerr cout

#define TRACE
#ifdef TRACE
#define trace(...)  __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names+1, ','); 
	cerr.write(names, comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif

#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define I insert
#define pll pair<ll,ll>
#define pii pair<int, int>

#define endl '\n'
#define all(v) v.begin(), v.end()
#define For(i, n) for(int i = 0;i < (int)n ; ++i)
#define Rev(i , n) for(int i = (int)n-1 ;i >= 0 ; --i)
#define Rep(i , n) for(int i = 1;i <= (int)n; ++i)
#define MP make_pair




struct segtree{
    vi seg; // O based
    int n;
    segtree() {};
    void clear(){
        n=0;
        seg.clear();
    }
    void build(vi val){
        n=val.size();
        seg.resize(2*n);
        for(int i=n;i<2*n;++i){
            seg[i]=val[i-n];
        }
        for(int i=n-1;i>0;--i) seg[i]=seg[i<<1]+seg[(i<<1)|1];
    }
    void update(int p,int v){
        p+=n; seg[p]=v;
        for(int i=p;i>1;i>>=1) seg[i>>1]=seg[i]+seg[i^1];
    }
    int query(int l,int r){
        /*assert(l<=r);*/ int ans=0;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if (l&1) ans+=seg[l++];
            if (r&1) ans+=seg[--r];
        }
        return ans;
    }
};
const int maxn=1e6+4;
int a[maxn];
int pos[maxn];

int idx[maxn];
bool cmp(int i,int j){
	return (a[i]<a[j]);
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	int n;
	cin>>n;
	Rep(i,n){
		cin>>a[i];
		idx[i]=i;
	}	
	sort(idx+1,idx+n+1,cmp);

	Rep(i,n) pos[idx[i]]=i;

	segtree left,right;

	vi l1(n+1,0);
	vi l2(n+1,1);
	l2[0]=0;
	left.build(l1);
	right.build(l2);
	ll x=0;
	Rep(i,n){
		// trace(i,pos[i]);
		right.update(pos[i],0);
		x+=left.query(pos[i]+1,n)*1ll*right.query(0,pos[i]-1);

		left.update(pos[i],1);
	}
	cout<<x<<endl;


	return 0;
}