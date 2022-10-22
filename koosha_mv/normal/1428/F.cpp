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
 
const int N=1e6+99;
 
int n,t;
string s;
ll ans,sum,BIT[N];
 
void add(int x,int val) { sum+=(n-x+1)*val; ++x;  while(x<N)  {  BIT[x]+=val;  x+=(x&-x);  } }
ll Get(int x) {  ++x;  ll res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 
 
int main(){
    cin>>n>>s;
    s=' '+s;
    f(i,1,n+1){
        if(s[i]=='1'){
            t++;
            int l=0,r=i,mid;
            while(l+1<r){
                mid=(l+r)/2;
                if(Get(mid)<t) r=mid;
                else l=mid;
            }
            add(i+1,-1);
            add(r,1);
        }
        else t=0;
        ans+=sum;
    }    
    cout<<ans;
}