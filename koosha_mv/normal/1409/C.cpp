#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);a
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,Lg=62,S=2;
 
int n,t,x,y,ans;
vector<int> v;

int check(int a,int b){
    int c=0;
    for(int i=a;i<=(n-1)*b+a;i+=b){
        c+=(i==x)+(i==y);
    }
    if(c==2 && (sz(v)==0 || (n-1)*b+a<lst(v))){
        v.clear();
        for(int i=a;i<=(n-1)*b+a;i+=b)
            v.pb(i);
    }
}

int main(){
    cin>>t;
    while(t--){
        v.clear();
        cin>>n>>x>>y;
        for(int i=1;i<55;i++)
            for(int j=1;j<55;j++)
                check(i,j);
        print(v,v.size());
    }
}