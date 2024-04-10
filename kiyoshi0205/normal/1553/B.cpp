#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define popcount __builtin_popcountll
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr long double eps=1e-9;
const long double PI=acosl(-1);
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const set<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const multiset<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,const T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,const T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp(void) noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

ll modinv(ll a,const ll m=mod) noexcept{
  ll b=m,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+m)%m;
}

ll moddevide(const ll a,const ll b) noexcept{return (a*modinv(b))%mod;}

vec modncrlistp,modncrlistm;

ll modncr(const ll n,const ll r) noexcept{
  if(n<r)return 0;
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1)modncrlistp[i]=modncrlistp[i-1]*i%mod;
    modncrlistm[n]=modinv(modncrlistp[n]);
    for(i=n;i>size;--i)modncrlistm[i-1]=modncrlistm[i]*i%mod;
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n,const ll m=mod){
  if(n<0)return 0;
  ll res=1;
  while(n>0){
    if(n&1)res=res*a%m;
    a=a*a%m;
    n>>=1;
  }
  return res;
}

constexpr ll gcd(const ll a,const ll b) noexcept{return (!b)?abs(a):(a%b==0)?abs(b):gcd(b,a%b);}
constexpr ll lcm(const ll a,const ll b) noexcept{return a/gcd(a,b)*b;}


struct stringalgorithm{
public:
  vector<int> suffix_array(const vector<int>& s,int upper){
    assert(0<=upper);
    for(int d:s){
      assert(0<=d&&d<=upper);
    }
    auto sa=sa_is(s,upper);
    return sa;
  }

  template<class T>vector<int> suffix_array(const vector<T>& s){
    int n=int(s.size());
    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int l,int r){return s[l]<s[r];});
    vector<int> s2(n);
    int now=0;
    for(int i=0;i<n;++i){
      if(i&&s[idx[i-1]]!=s[idx[i]])++now;
      s2[idx[i]]=now;
    }
    return sa_is(s2,now);
  }

  vector<int> suffix_array(const string& s){
    int n=int(s.size());
    vector<int> s2(n);
    for(int i=0;i<n;++i){
      s2[i]=s[i];
    }
    return sa_is(s2,255);
  }

  template<class T>
  vector<int> lcp_array(const vector<T>& s,const vector<int>& sa){
    int n=int(s.size());
    assert(n>=1);
    vector<int> rnk(n);
    for(int i=0;i<n;++i)rnk[sa[i]]=i;
    vector<int> lcp(n-1);
    int h=0;
    for(int i=0;i<n;++i){
      if(h>0)--h;
      if(rnk[i]==0)continue;
      for(int j=sa[rnk[i]-1];j+h<n&&i+h<n;++h){
        if(s[j+h]!=s[i+h])break;
      }
      lcp[rnk[i]-1]=h;
    }
    return lcp;
  }

  vector<int> lcp_array(const string& s,const vector<int>& sa){
    int n=int(s.size());
    vector<int> s2(n);
    for(int i=0;i<n;++i)s2[i]=s[i];
    return lcp_array(s2,sa);
  }

  template<class T>vector<int> z_algorithm(const vector<T>& s){
    int n=int(s.size());
    if(n==0)return{};
    vector<int> z(n);
    z[0]=0;
    for(int i=1,j=0;i<n;++i){
      int& k=z[i];
      k=(j+z[j]<=i)?0:min(j+z[j]-i,z[i-j]);
      while(i+k<n&&s[k]==s[i+k])++k;
      if(j+z[j]<i+z[i])j=i;
    }
    z[0]=n;
    return z;
  }

  vector<int> z_algorithm(const string& s){
    int n=int(s.size());
    vector<int> s2(n);
    for(int i=0;i<n;++i)s2[i]=s[i];
    return z_algorithm(s2);
  }

private:
  vector<int> sa_naive(const vector<int>& s){
    int n=int(s.size());
    vector<int> sa(n);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),[&](int l,int r){
      if(l==r)return false;
      while(l<n&&r<n){
        if(s[l]!=s[r])return s[l]<s[r];
        ++l;++r;
      }
      return l==n;
    });
    return sa;
  }

  vector<int> sa_doubling(const vector<int>& s){
    int n=int(s.size());
    vector<int> sa(n),rnk=s,tmp(n);
    iota(sa.begin(),sa.end(),0);
    for(int k=1;k<n;k<<=1){
      auto cmp=[&](int x,int y){
        if(rnk[x]!=rnk[y])return rnk[x]<rnk[y];
        int rx=x+k<n?rnk[x+k]:-1;
        int ry=y+k<n?rnk[y+k]:-1;
        return rx<ry;
      };
      sort(sa.begin(),sa.end(),cmp);
      tmp[sa[0]]=0;
      for(int i=1;i<n;++i){
        tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
      }
      swap(tmp,rnk);
    }
    return sa;
  }

  template<int THRESHOLD_NAIVE=10,int THRESHOLD_DOUBLING=40>
  vector<int> sa_is(const vector<int>& s,int upper){
    int n=int(s.size());
    if(n==0)return{};
    if(n==1)return{0};
    if(n==2){
      if(s[0]<s[1]){
        return{0,1};
      }else{
        return{1,0};
      }
    }
    if(n<THRESHOLD_NAIVE){
      return sa_naive(s);
    }
    if(n<THRESHOLD_DOUBLING){
      return sa_doubling(s);
    }

    vector<int> sa(n);
    vector<bool> ls(n);
    for(int i=n-2;i>=0;--i){
      ls[i]=(s[i]==s[i+1])?ls[i+1]:(s[i]<s[i+1]);
    }
    vector<int> sum_l(upper+1),sum_s(upper+1);
    for(int i=0;i<n;++i){
      if(!ls[i]){
        ++sum_s[s[i]];
      }else{
        ++sum_l[s[i]+1];
      }
    }
    for(int i=0;i<=upper;++i){
      sum_s[i]+=sum_l[i];
      if(i<upper)sum_l[i+1]+=sum_s[i];
    }

    auto induce=[&](const vector<int>& lms){
      fill(sa.begin(),sa.end(),-1);
      vector<int> buf(upper+1);
      copy(sum_s.begin(),sum_s.end(),buf.begin());
      for(auto d:lms){
        if(d==n)continue;
        sa[buf[s[d]]++]=d;
      }
      copy(sum_l.begin(),sum_l.end(),buf.begin());
      sa[buf[s[n-1]]++]=n-1;
      for(int i=0;i<n;++i){
        int v=sa[i];
        if(v>=1&&!ls[v-1]){
          sa[buf[s[v-1]]++]=v-1;
        }
      }
      copy(sum_l.begin(),sum_l.end(),buf.begin());
      for(int i=n-1;i>=0;--i){
        int v=sa[i];
        if(v>=1&&ls[v-1]){
          sa[--buf[s[v-1]+1]]=v-1;
        }
      }
    };

    vector<int> lms_map(n+1,-1);
    int m=0;
    for(int i=1;i<n;++i){
      if(!ls[i-1]&&ls[i]){
        lms_map[i]=m++;
      }
    }
    vector<int> lms;
    lms.reserve(m);
    for(int i=1;i<n;++i){
      if(!ls[i-1]&&ls[i]){
        lms.push_back(i);
      }
    }

    induce(lms);

    if(m){
      vector<int> sorted_lms;
      sorted_lms.reserve(m);
      for(int v:sa){
        if(lms_map[v]!=-1)sorted_lms.push_back(v);
      }
      vector<int> rec_s(m);
      int rec_upper=0;
      rec_s[lms_map[sorted_lms[0]]]=0;
      for(int i=1;i<m;++i){
        int l=sorted_lms[i-1],r=sorted_lms[i];
        int end_l=(lms_map[l]+1<m)?lms[lms_map[l]+1]:n;
        int end_r=(lms_map[r]+1<m)?lms[lms_map[r]+1]:n;
        bool same=true;
        if(end_l-l!=end_r-r){
          same=false;
        }else{
          while(l<end_l){
            if(s[l]!=s[r])break;
            ++l;
            ++r;
          }
          if(l==n||s[l]!=s[r])same=false;
        }
        if(!same)++rec_upper;
        rec_s[lms_map[sorted_lms[i]]]=rec_upper;
      }

      auto rec_sa=sa_is<THRESHOLD_NAIVE,THRESHOLD_DOUBLING>(rec_s,rec_upper);

      for(int i=0;i<m;++i){
        sorted_lms[i]=lms[rec_sa[i]];
      }
      induce(sorted_lms);
    }
    return sa;
  }
};


ll N,M,K,H,W,A,B,C,D;
string s,t;
ll ans;
int main(){
  startupcpp();
  // stringalgorithm sol;
int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,k;
  cin>>s>>t;
  N=s.size();
  K=t.size();
  bool f=false;
  rep(i,N){
    For(j,i,N){
      // i -> j -> 2j-K-i+1
      if(j-i+1>K)break;
      if(j*2-K-i+1<0)continue;
      rep(k,j-i+1){
        if(t[k]!=s[i+k])break;
      }
      if(k!=j-i+1)break;
      For(k,j-i+1,K){
        if(t[k]!=s[j-(k-(j-i))])break;
      }
      if(k==K){
        f=true;
        break;
      }
    }
    if(f)break;
  }
  if(f)printYES;
  else printNO;
}
}