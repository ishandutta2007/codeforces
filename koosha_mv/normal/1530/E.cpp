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

const int N=1e6+99,Z=27;

int n,t,mn,mn2,mark[Z];
string s,q;

void case1(){
    mark[mn]-=2;
    s+=char('a'+mn);
    s+=char('a'+mn);
    f(i,2,n){
        if(s[i-1]-'a'!=mn && mark[mn]) 
            s+=char('a'+mn),mark[mn]--;
        else{
            f(j,mn+1,Z)
                if(mark[j]){
                    s+=char('a'+j);
                    mark[j]--;
                    break;
                }
        }
    }
    cout<<s<<endl;
}
void case2(){
    f(i,mn+1,Z)
        if(mark[i]){
            mn2=i;
            break;
        }
    s+=char('a'+mn);
    s+=char('a'+mn2);
    if(mark[mn]+mark[mn2]==n){
        f(i,1,mark[mn2])
            s+=char('a'+mn2);
        f(i,1,mark[mn])
            s+=char('a'+mn);
    }
    else{
        mark[mn]--;
        mark[mn2]--;
        //f(i,0,Z) cout<<mark[i]<<" ";
        f(i,2,n){
            f(j,0,Z){
                if(mark[j] && (j!=mn2 || s[i-1]-'a'!=mn)){
                    mark[j]--;
                    s+=char('a'+j);
                    break;
                }
            }
        }
    }
    cout<<s<<endl;
}
void solve(){
    f(i,0,Z)
        mark[i]=0;
    cin>>s;
    n=s.size();
    f(i,0,s.size()){ mark[s[i]-'a']++; if(mark[s[i]-'a']==n){ cout<<s<<endl; return ; }}
    s="";
    f(i,0,Z)
      if(mark[i]==1){
         cout<<char('a'+i);
         mark[i]--;
         f(j,0,Z)
            while(mark[j]--)
               cout<<char('a'+j);
        cout<<endl;
         return ;
      }
    f(i,0,Z)
        if(mark[i]){
            mn=i;
            if((mark[i]-1)*2<=n && 1<mark[i]) case1();
            else case2();
            return ;
        }
}

int main(){
    cin>>t;
    while(t--)
        solve();
}