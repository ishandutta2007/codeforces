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

int n,t,np,ans,pr[20];
vector<int> divi,m[(1<<18)];


void do_it(){
    int c=n;
    for(int i=2;i*i<=c;i++){
        if(c%i==0){
            pr[np++]=i;
            while(c%i==0)
                c/=i;
        }
    }
    if(1<c)
        pr[np++]=c;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            divi.pb(i);
            if(i*i!=n)
                divi.pb(n/i);
        }
    }
    divi.pb(n);
    f(i,1,(1<<np)) m[i].clear();
    f(i,0,divi.size()){
        int u=divi[i],mask=0;
        f(j,0,np)
            if(u%pr[j]==0)
                mask|=(1<<j);
        m[mask].pb(u);
    }
}
void case1(){
    ans=0;
    f(i,0,divi.size())
        cout<<divi[i]<<" ";
    cout<<'\n';
}
void case2(){
    vector<int> v;
    f(i,0,np)
        for(int mask=(1<<(i+1))-1;(1<<i)<=mask;mask--)
            v.pb(mask);
    if(np==2){
        if(1<m[(1<<np)-1].size()){
            ans=0;
            cout<<lst(m[(1<<np)-1])<<" ";
            m[(1<<np)-1].pop_back();
        }
        else
            ans=1;
        f(i,0,sz(v)){
            int mask=v[i];
            f(j,0,m[mask].size())
                cout<<m[mask][j]<<" ";
        }
        cout<<endl;
    }
    else{
        ans=0;
        swap(v[sz(v)-1],v[sz(v)-2]);
        f(i,0,sz(v)){
            int mask=v[i];
            f(j,0,m[mask].size())
                cout<<m[mask][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>t;
    while(t--){
        np=0;
        divi.clear();
        cin>>n;
        do_it();
        if(np==1) case1();
        else case2();
        cout<<ans<<'\n';
    }
}