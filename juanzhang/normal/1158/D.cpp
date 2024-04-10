#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=2021;
int n;char str[maxn];

struct point{
  int x,y,id;
}A[maxn];

point operator-(point A,point B){
  return{A.x-B.x,A.y-B.y};
}
ll operator*(point A,point B){
  return 1ll*A.x*B.y-1ll*B.x*A.y;
}

point O;int ans[maxn];

signed main(){
  cin>>n;
  rep(i,1,n)scanf("%d%d",&A[i].x,&A[i].y),A[i].id=i;
  scanf("%s",str+1);
  rep(i,1,n)if(A[i].y<A[1].y||(A[i].y==A[1].y&&A[i].x<A[1].x)){
    swap(A[1],A[i]);
  }
//  rep(i,1,n)printf("%d ",A[i].id);
  int cur=1,len=n;ans[1]=A[1].id;
  while(cur<n-1){
    O=A[1];
    sort(A+2,A+len+1,[](point P,point Q){
      return(O-P)*(O-Q)>0;
    });
    if(str[cur]=='L'){
      ans[++cur]=A[2].id,A[1]=A[2];rep(i,2,--len)A[i]=A[i+1];
    }else{
      ans[++cur]=A[len].id,A[1]=A[len--];
    }
  }
  ans[n]=A[2].id;
  rep(i,1,n)printf("%d ",ans[i]);
  return 0;
}