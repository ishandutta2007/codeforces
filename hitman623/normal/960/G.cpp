#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int root=565042129;
const int root_1=950391366;
const int root_pw=1<<20;
int expo(int base,int exponent){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%hell;
        base=(1LL*base*base)%hell;
        exponent>>=1;
    }
    return ans%hell;
}
void fft(vi&a,bool invert){
    int i,j,n=(int)a.size();
    for(i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1){
        int wlen=invert?root_1:root;
        for(i=len;i<root_pw;i<<=1){
            wlen=(wlen*wlen%hell);
        }
        for(i=0;i<n;i+=len){
            int w=1;
            for(j=0;j<len/2;++j){
                int u=a[i+j],v=(int)(a[i+j+len/2]*w%hell);
                a[i+j]=(u+v+hell)%hell;
                a[i+j+len/2]=(u-v+hell)%hell;
                w=(w*wlen%hell);
            }
        }
    }
    if(invert){
        int nrev=expo(n,hell-2);
        for(i=0;i<n;++i){
            a[i]=(a[i]*nrev%hell);
        }
    }
}
void multiply(const vi &a,const vi &b,vi &res){
    vi fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=fa[i];
    }
}
vi mul(int l,int r){
    if(l==r){
        vi g={l,1};
        return g;
    }
    int m=(l+r)/2;
    vi v1=mul(l,m),v2=mul(m+1,r),v3;
    multiply(v1,v2,v3);
    return v3;
}
int s(int n,int k){
    vi v=mul(1,n-1);
    return v[k-1];
}
const int M=200006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M){
        f[i]=(1LL*i*f[i-1])%hell;
    }
    inv[M-1]=expo(f[M-1],hell-2,hell);
    for(int i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%hell;
    }
}
int C(int n,int r){
    return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
void solve(){
    compute();
    int n,a,b;
    cin>>n>>a>>b;
    if(!a || !b) {cout<<0<<endl;return;}
    if(n==1){
        if(a==1 and b==1) cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    if(n==2){
        if(a+b==3) cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    cout<<(s(n-1,a+b-2)*C(a+b-2,a-1))%hell;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}