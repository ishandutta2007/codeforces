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
 
const int N=1e6+99;
 
int n,m,t,ok[2],a[55][55];
 
int main(){
   cin>>t;
   while(t--){
       ok[0]=ok[1]=0;
       cin>>n>>m;
       f(i,0,n)
           f(j,0,m){
               char c;
               cin>>c;
               if(c=='R') ok[(i%2+j%2)%2]=1;
               if(c=='W') ok[1-((i%2+j%2)%2)]=1;
           }
       if(ok[0]==0){
           cout<<"YES"<<endl;
           f(i,0,n){
               f(j,0,m){
                   if((i+j)&1) cout<<"R";
                   else cout<<"W";
               }
               cout<<endl;
           }
       }
       else{
           if(ok[1]==0){
               cout<<"YES"<<endl;
               f(i,0,n){
               f(j,0,m){
                   if((i+j)&1) cout<<"W";
                   else cout<<"R";
               }
               cout<<endl;
           }
           }
           else cout<<"NO"<<endl;
       }
   }
}