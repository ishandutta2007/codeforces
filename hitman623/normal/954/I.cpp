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
#define hell        1000000007
#define PI          3.141592653589793l
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

typedef complex < double > base ;
void fft(vector<base> &a,bool invert){
    int i,j,n=(int)a.size();
    for (i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    for(int len=2;len<=n;len<<= 1){
        double ang=2*PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for(i=0;i<n;i+=len){
            base w(1);
            for(j=0;j<len/2;++j){
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(i=0;i<n;++i){
            a[i]/=n;
        }
    }
}

vector<base> fs[6],ft[6];
int visi[6][6],ps[6][200005],pt[6][200005],a[200005][6][6];
void solve(){
    string s,t;
    cin>>s>>t;
    reverse(all(t));
    int n=1;
    while(n<sz(s)) n<<=1;
    n<<=1;
    rep(i,0,6){
        rep(j,0,sz(s)){
            fs[i].pb(s[j]-'a'==i);
        }
        fs[i].resize(n);
        fft(fs[i],false);
    }
    rep(i,0,6){
        rep(j,0,sz(t)){
            ft[i].pb(t[j]-'a'==i);
        }
        ft[i].resize(n);
        fft(ft[i],false);
    }
    rep(i,0,6){
        rep(j,0,6){
            if(i==j) continue;
            vector<base> temp(n);
            vi res(n),res2;
            rep(k,0,n){
                temp[k]=fs[i][k]*ft[j][k];
            }
            fft(temp,true);
            rep(k,0,n){
                res[k]=(int)(temp[k].real()+0.5);
            }
            rep(k,0,sz(s)-sz(t)+1){
                int h=res[sz(t)+k-1];
                if(h) a[k][i][j]=1,a[k][j][i]=1;
            }
        }
    }
    rep(i,0,sz(s)-sz(t)+1){
        int v[6]={0},cnt=0;
        function<void(int)> dfs=[&](int u){
            v[u]=cnt;
            rep(l,0,6){
                if(a[i][u][l] && !v[l]){
                    dfs(l);
                }
            }
        };
        rep(j,0,6){
            if(!v[j]){
                ++cnt;
                dfs(j);
            }
        }
        cout<<6-cnt<<" ";
    }
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