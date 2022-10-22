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
 
const int N=1e6+99,mod=1e9+7;

int n,b=-1,c,a[N];
string s,t;

int main(){
   cin>>s;
   f(i,0,s.size()){
      if(s[i]!='0'){
         f(j,i,s.size())
            t+=s[j];
         break;
      }
   }
   s=t;
   //cout<<s<<endl;
   f(i,0,s.size()){
      if(s[i]=='.')
         b=i;
   }
   if(b==-1) b=s.size(),s+='.';
   if(b==0){
      f(i,1,s.size()){
         if(s[i]!='0'){
           // cout<<i<<endl;
            int mv=0;
            t="";
            cout<<s[i];
            f_(j,s.size()-1,i+1){
               if(s[j]!='0'){
                  mv=1;
               }
               if(mv)
                  t+=s[j];
            }
            if(t.size()) cout<<'.';
            f_(j,t.size()-1,0)
               cout<<t[j];
            cout<<'E'<<-i<<endl;
            return 0;
         }
      }
   }
   int mv=0;
   f_(i,s.size()-1,0){
      if(s[i]!='0' && s[i]!='.'){
         mv=i;
         break;
      }
   }
   cout<<s[0];
   if(mv) cout<<'.';
   f(i,1,mv+1){
      if(s[i]!='.')
         cout<<s[i];
   }
   b--;
   if(b){
      cout<<'E'<<b<<endl;
   }
}