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

const int N=3e5+99,mod=1e9+7,T1=2,T2=500000004;

int n,a[N],Pow[N],IPow[N],seg[2][N<<1];

void make(){
    IPow[0]=Pow[0]=1;
    f(i,1,N)
        Pow[i]=1ll*Pow[i-1]*T1%mod,IPow[i]=1ll*IPow[i-1]*T2%mod;
}
void add(int x,int val,int s){
    x+=n;
    while(x){
        Add(seg[s][x], val);
        x/=2;
    }
}
void Upd(int x){
    add(x,Pow[x],0);
    add(x,Pow[n-x-1],1);
}
int Get(int l, int r,int s) {
  int res = 0;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) Add(res, seg[s][l++]);
    if (r&1) Add(res, seg[s][--r]);
  }
  return res;
}
int Get_hash1(int l,int r){
    l--;
    return 1ll *(Get(0,r,0)-Get(0,l,0)+mod) *IPow[l+1] %mod;
}
int Get_hash2(int l,int r){
    r++;
    return 1ll *(Get(l,n-1,1)-Get(r,n-1,1)+mod) *IPow[n-r] %mod;
}

int main(){
    make();
    cin>>n;
    f(i,0,n){ gett(a[i]); a[i]--; }
    f(i,0,n){
        int l=min(a[i],n-a[i]-1);
        if(Get_hash1(a[i]-l,a[i]-1)!=Get_hash2(a[i]+1,a[i]+l)) return cout<<"YES",0;
        Upd(a[i]);
    }
    cout<<"NO";
}