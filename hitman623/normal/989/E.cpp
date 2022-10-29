#include <bits/stdc++.h>

#define pii         pair<int,int>
#define vii         vector<pii>
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)

using namespace std;
int n,x[202],y[202],q,f[202];
double w[202][202],p[15][202][202];
map<pair<int,pii>,set<int>> mp;
void mul(double a[202][202],double b[202][202]){
    double c[202][202]={0};
    rep(i,1,n+1){
        rep(j,1,n+1){
            rep(k,1,n+1){
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            a[i][j]=c[i][j];
        }
    }
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>x[i]>>y[i];
    }
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            int a=y[j]-y[i],b=x[i]-x[j],c=y[i]*(x[j]-x[i])-x[i]*(y[j]-y[i]);
            int g=abs(__gcd(a,__gcd(b,c)));
            a/=g,b/=g,c/=g;
            pair<int,pii> l={a,{b,c}},r={-a,{-b,-c}};
            mp[min(l,r)].insert(i);
            mp[min(l,r)].insert(j);
        }
    }
    for(auto i:mp){
        for(auto j:i.y){
            f[j]++;
        }
    }
    for(auto i:mp){
        int cnt=sz(i.y);
        for(auto j:i.y){
            for(auto k:i.y){
                w[j][k]+=1.0l/(f[j]*cnt);
            }
        }
    }
    rep(i,0,14){
        rep(j,1,n+1){
            rep(k,1,n+1){
                p[i][j][k]=w[j][k];
            }
        }
        mul(w,w);
    }
    cin>>q;
    while(q--){
        int t,m;
        double v[202]={0},vv[202]={0},ans=0;
        cin>>t>>m;
        m--;
        v[t]=1;
        rep(i,0,14){
            if((m>>i)&1){
                rep(j,1,n+1){
                    rep(k,1,n+1){
                        vv[j]+=p[i][j][k]*v[k];
                    }
                }
                rep(i,1,n+1){
                    v[i]=vv[i];
                    vv[i]=0;
                }
            }
        }
        for(auto i:mp){
            double cur=0;
            for(auto j:i.y){
                cur+=v[j];
            }
            cur/=sz(i.y);
            ans=max(ans,cur);
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}