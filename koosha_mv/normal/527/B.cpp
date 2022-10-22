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
 
const int N=5e5+9,Z=27;

int n,ans,mark[Z][Z];
string s,t;
pair<int,pair<int,int> > res;

int main(){
   cin>>n;
   cin>>s>>t;
   s=' '+s;
   t=' '+t;
   f(i,1,n+1){
      ans+=(s[i]!=t[i]);
      mark[s[i]-'a'][t[i]-'a']=i;
   }
   f(a1,0,Z)
      f(a2,0,Z)
         f(b1,0,Z)
            f(b2,0,Z)
               if(mark[a1][a2] && mark[b1][b2])
                  maxm(res,mp((a1==b2)+(a2==b1)-(a1==a2)-(b1==b2),mp(mark[a1][a2],mark[b1][b2])))
   if(res.F==0){
      cout<<ans<<endl;
      cout<<-1<<" "<<-1<<endl;
      return 0;
   }
   cout<<ans-res.F<<endl;
   cout<<res.S.F<<" "<<res.S.S<<endl;
}