// Hydro submission #62f64a1cef830476c2f170fb@1660307997185
#include<bits/stdc++.h>
using namespace std;
long long multicases=0,mod=1000000007LL;
/*print pairs*/    template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p){return os<<"("<<p.first<<","<<p.second<<")";}
/*print vectors*/  template<class t> ostream& operator<<(ostream& os,const vector<t>& p){for(auto i:p) cout<<i<<" "; return os;}
/*check min*/      template<typename T, typename U> bool chmin(T &a, const U b) { if (a > b) {a = b; return true;} return false; }
/*check max*/      template<typename T, typename U> bool chmax(T &a, const U b) { if (a < b) {a = b; return true;} return false; }
/*yes or no*/      inline string YN(bool x,string Y="Yes",string N="No"){return (x)?(Y):(N);}
/*quick power*/    template<typename T>T quickPow(T a,T b,T m=mod){T res=1;a%=m;while(b>0){res=(b&1)?(res*a%m):(res);a=a*a%m;b>>=1;}return res;}
/*union find set*/ struct UnionFind{int N;vector<int> fa;UnionFind(int n=100005):N(n){fa.resize(n+1);for(int i=1;i<=n;++i)fa[i]=i;}int root(int x){return ((fa[x]==x)?(x):(fa[x]=root(fa[x])));}void unite(int a,int b){fa[root(a)]=root(b);}bool same(int a,int b){return root(a)==root(b);}};
/*segment tree*/   template<typename T>struct SegmentTree{unsigned int N;vector<T> tree,lazy_tag;T build(unsigned int l,unsigned int r,unsigned int p,const vector<T> &original){if(l==r){return tree[p]=original[l];}unsigned int m=l+((r-l)>>1);return tree[p]=build(l,m,p<<1,original)+build(m+1,r,(p<<1)|1,original);}void update(unsigned int l,unsigned int r,T c,unsigned int s=0,unsigned int t=0,unsigned int p=1){if(p==1){s=1,t=N;}if(l<=s&&t<=r){tree[p]+=(t-s+1)*c,lazy_tag[p]+=c;return;}unsigned int m=s+((t-s)>>1);if(lazy_tag[p]){tree[p<<1]+=lazy_tag[p]*(m-s+1),tree[(p<<1)|1]+=lazy_tag[p]*(t-m),lazy_tag[p<<1]+=lazy_tag[p],lazy_tag[(p<<1)|1]+=lazy_tag[p];}lazy_tag[p]=0;if(l<=m){update(l,r,c,s,m,p<<1);}if(r>m){update(l,r,c,m+1,t,(p<<1)|1);}tree[p]=tree[p<<1]+tree[(p<<1)|1];}T getsum(unsigned int l,unsigned int r,unsigned int s=0,unsigned int t=0,unsigned int p=1){if(p==1){s=1,t=N;}if(l<=s&&t<=r) {return tree[p];}unsigned int m=s+((t-s)>>1);if(lazy_tag[p]){tree[p<<1]+=lazy_tag[p]*(m-s+1),tree[(p<<1)|1]+=lazy_tag[p]*(t-m),lazy_tag[p<<1]+=lazy_tag[p],lazy_tag[(p<<1)|1]+=lazy_tag[p];}lazy_tag[p]=0;T sum=0;if(l<=m) {sum=getsum(l,r,s,m,p<<1);}if(r>m) {sum+=getsum(l,r,m+1,t,(p<<1)|1);}return sum;}SegmentTree(vector<T> original){N=original.size();original.insert(original.begin(),0),tree.resize(4*N),lazy_tag.resize(4*N),build(1,N,1,original),tree[0]=N;}};
/*discretization*/ template<typename S,typename T>vector<T> discrete(vector<S> vec,bool (*cmp)(S,S)=less<S>()){vector<S> b=vec;vector<T> ans;sort(vec.begin(),vec.end(),cmp);vec.erase(unique(vec.begin(),vec.end()),vec.end());for(int i=0;i<b.size();++i) ans.push_back(lower_bound(vec.begin(),vec.end(),b[i])-vec.begin());return ans;}
/*binary search*/  template<typename T>T binarySearch(T left,T right,bool (*checker)(T),bool smallest=true){while(1){T mid=(left+right)/2;if(left+2>=right){if(smallest){if(checker(left)) return left;else if(checker(mid)) return mid;else return right;}else{if(checker(right)) return right;else if(checker(mid)) return mid;else return left;}}if(checker(mid)){if(smallest) right=mid;else left=mid;}else{if(smallest) left=mid;else right=mid;}}}
/*ternary search*/ template<typename T>T ternarySearch(T left,T right,T (*func)(T),bool smallest=true,T eps=1e-6){while(right-left>eps){T mid=(left+right)/2,mid1=mid-eps,mid2=mid+eps;if(smallest){if(func(mid1)>func(mid2)) left=mid;else right=mid;}else{if(func(mid1)<func(mid2)) left=mid;else right=mid;}}return left;}
using uint=unsigned int; using i64=long long; using u64=unsigned long long; using pii=pair<int,int>; using puu=pair<unsigned,unsigned>; using p64=pair<long long,long long>; using pu64=pair<unsigned long long,unsigned long long>;
#define f0(i,n)   for(long long i=0;i<n;++i)
#define f1(i,n)   for(long long i=1;i<=n;++i)
#define all(n)    n.begin(),n.end()
#define pb        push_back
#define mp        make_pair
#define over(n)   {cout<<n<<endl; return 0;}
#define inf       0x3f3f3f3f
#define linf      0x3f3f3f3f3f3f3f3fLL

signed Main()
{
    //codeforces 3C
    char c[3][3];
    f0(i,3) f0(j,3) cin>>c[i][j];
    int Xcnt,Ocnt;
    Xcnt=Ocnt=0;
    f0(i,3) f0(j,3) if(c[i][j]=='X') Xcnt++;
    f0(i,3) f0(j,3) if(c[i][j]=='0') Ocnt++;
    if(Xcnt-Ocnt==0||Xcnt-Ocnt==1) ;
    else over("illegal");
    i64 Xwin,Owin;
    Xwin=Owin=0;    
    f0(i,3) if(c[i][0]=='X'&&c[i][1]=='X'&&c[i][2]=='X') Xwin++;
    f0(i,3) if(c[0][i]=='X'&&c[1][i]=='X'&&c[2][i]=='X') Xwin++;
    f0(i,3) if(c[i][0]=='0'&&c[i][1]=='0'&&c[i][2]=='0') Owin++;
    f0(i,3) if(c[0][i]=='0'&&c[1][i]=='0'&&c[2][i]=='0') Owin++; 
    if(c[0][0]=='X'&&c[1][1]=='X'&&c[2][2]=='X') Xwin++;
    if(c[0][0]=='0'&&c[1][1]=='0'&&c[2][2]=='0') Owin++;
    if(c[0][2]=='X'&&c[1][1]=='X'&&c[2][0]=='X') Xwin++;
    if(c[0][2]=='0'&&c[1][1]=='0'&&c[2][0]=='0') Owin++;
    if(Xwin&&Owin) over("illegal");
    if(Owin&&Xcnt>Ocnt) over("illegal");
    if(Xwin&&Xcnt-1<Ocnt) over("illegal");
    if(Xwin) over("the first player won");
    if(Owin) over("the second player won");
    if(Xcnt+Ocnt==9) over("draw");
    if(Xcnt==Ocnt) over("first");
    over("second");
}
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0),cout.setf(ios::fixed),cout.precision(20);
    unsigned long long T=1LL;
    if(multicases) cin>>T;
    while(T--) Main();
    return 0;
}