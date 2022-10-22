#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e3+9,inf=1e9+9;

int n,t,a[N];

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int> > v(n);
        f(i,0,n){ cin>>v[i].F; v[i].S=v[i].F; }
        f(io,0,n){
            pair<int,int> mx=mp(0,0);
            f(j,0,sz(v))
                if(mx<mp(v[j].F,j))
                    mx=mp(v[j].F,j);
            f(j,0,sz(v))
                v[j].F=__gcd(v[j].F,mx.F);
            cout<<v[mx.S].S<<" ";
            v.erase(v.begin()+mx.S);
        }
        cout<<endl;
    }
}