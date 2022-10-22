#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef long long ll;
const int maxn=5e5+10;
int n;
struct point{
  int x,y;
}A[maxn];
ll area(point P,point Q){
  return 1ll*P.x*Q.y-1ll*P.y*Q.x;
}
ll vnx[maxn];__int128 prs[maxn],pp[maxn],prx[maxn],pry[maxn];
__int128 query(int l,int r){
  if(l<r)return prs[r-1]-prs[l-1]+area(A[r],A[l]);
  if(l>r)return prs[n]-prs[l-1]+prs[r-1]+area(A[r],A[l]);
  return -1;
}
__int128 queryA(int l,int r){
  return A[l].y*(prx[r]-prx[l+1])-A[l].x*(pry[r]-pry[l+1]);
}
__int128 query2(int l,int r){
  return r>=l+2?pp[r-1]-pp[l]-(r-l-1)*prs[l-1]+queryA(l,r):0;
}
__int128 query3(int j,int i){
  return j>=i+2?(j-i-1)*(prs[n]+prs[i-1])-pp[j-1]+pp[i]-queryA(i,j):0;
}
void write(__int128 x){
  if(x)write(x/10),putchar(x%10|48);
}

int main(){
  cin>>n;
  rep(i,1,n)A[i].x=read(),A[i].y=read();
  rep(i,1,n)vnx[i]=area(A[i],A[i%n+1]),prs[i]=prs[i-1]+vnx[i],pp[i]=pp[i-1]+prs[i],prx[i]=prx[i-1]+A[i].x,pry[i]=pry[i-1]+A[i].y;
  __int128 ans=0;
  rep(i,1,n){
    int l=i+2,r=n-(i==1),pos=i+1;
    while(l<=r){
      int mid=(l+r+1)/2;
      __int128 x=-query(i,mid);
      __int128 y=-query(mid,i);
      __int128 tp=x-y;
      tp<0?l=(pos=mid)+1:r=mid-1;
    }
    ans-=query3(pos,i);
    ans+=query2(i,pos);
    ans+=query3(n-(i==1),i)-query3(pos,i);
    ans-=query2(i,n-(i==1))-query2(i,pos);
  }
  cout<<(int)(ans%((int)1e9+7))<<endl;
  return 0;
}