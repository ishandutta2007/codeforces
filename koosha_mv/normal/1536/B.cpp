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

const int N=5e5+99,Z=26;

int t,n,a[N],ans[N];
string s;
vector<string> v;

bool check(string l){
   //cout<<l<<endl;
   f(i,0,n-l.size()+1){
      int ok=1;
      f(j,0,l.size())
         if(l[j]!=s[i+j])
            ok=0;
      if(ok)
         return 0;
   }
   return 1;
}
int main(){
   string e="";
   f(i,0,Z){
      e=char('a'+i);
      v.pb(e);
   }
   f(i,0,Z)
      f(j,0,Z){
         e=char('a'+i);
         e+=char('a'+j);
         v.pb(e);
      }
   f(i,0,Z)
      f(j,0,Z)
         f(k,0,Z){
            e=char('a'+i);e+=char('a'+j);e+=char('a'+k);
            v.pb(e);
         }
   cin>>t;
   while(t--){
      cin>>n>>s;
      f(i,0,v.size())
         if(check(v[i])){
            cout<<v[i]<<endl;
            break;
         }
   }
}