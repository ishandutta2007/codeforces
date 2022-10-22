#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=5e5+99,Mx=1e9;

int n,t,a[N],sum;

int main(){
    cin>>t;
    while(t--){
        sum=0;
        cin>>n;
        f(i,0,n){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum&1) cout<<"T"<<'\n';
        else{
            int ans=0;
            f(i,0,n) if(sum/2<a[i]) ans=1;
            if(ans) cout<<"T"<<endl;
            else cout<<"HL"<<endl;
        }
    }
    
}