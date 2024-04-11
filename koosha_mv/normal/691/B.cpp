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

int n,a[N];
string s;
char v[15]={'A','H','I','M','V','v','O','o','T','U','X','x','Y','W','w'};

int main(){
   int ans=1;
   cin>>s;
   n=s.size();
   f(i,0,n){
      int b=0;
      if(s[i]==s[n-1-i]) b=1;
      f(j,0,15) if(s[i]==v[j]) b++;
      if((s[i]=='p' && s[n-i-1]=='q') || (s[i]=='b' && s[n-i-1]=='d') || (s[i]=='q' && s[n-i-1]=='p') || (s[i]=='d' && s[n-i-1]=='b') || b==2){
         ans=ans;
      }
      else{
        // cout<<i<<endl;
         ans=0;
      }
   }
   if(ans) cout<<"TAK";
   else cout<<"NIE";
}