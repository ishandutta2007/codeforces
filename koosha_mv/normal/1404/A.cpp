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
#define gett(x) scanf("%d",&x);
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
 
const int N=1e6+99;

int n,t,k;
string s;

int main(){
    cin>>t;
    while(t--){
        int t0=0,t1=0,n1=0,n2=0,n3=0,n4=0;
        cin>>n>>k;
        cin>>s;
        f(i,0,k){
            t0=t1=0;
            for(int j=i;j<n;j+=k){
                if(s[j]=='0') t0=1;
                if(s[j]=='1') t1=1;
            }
            if(!t1 && t0) n1++;
            if(!t0 && t1) n2++;
            if(!t0 && !t1) n3++;
            if(t0 && t1) n4++;
        }
        if(k/2<=n1+n3 && k/2<=n2+n3 && n4==0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}