#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int P=1e9+7;
void Add(int&x,int y){if((x+=y)>=P)x-=P;}
int len,n,A[3400],k,B,dp[2][3400][2][2];char str[3400];

int spre(int x){
  return 1ll*x*(x+1)/2%P;
}
int cpre(int x){
  x=min(x,2*B-2),x=max(x,0);
  return (spre(min(B-1,x))+(x>B-1?1ll*spre(B-2)-spre(2*B-2-x-1)+P:0))%P;
}
int calc(int l,int r){
  r=min(r,2*B-2),l=max(l,0);
  return l<=r?(r-l+1ll+cpre(r)-cpre(l-1)+P)%P:0;
}

int main(){
  scanf("%d%d%s",&B,&k,str+1),len=strlen(str+1),reverse(str+1,str+len+1);
  while(len){
    ll rem=0;
    per(i,len,1){
      rem=rem*10+str[i]-48;
      str[i]=rem/B+48,rem%=B;
    }
    A[++n]=rem;
    while(len&&str[len]=='0')len--;
  }
  int sel=1,ans=0;
  dp[0][0][1][0]=1;
  rep(i,1,n){
    memset(dp[sel],0,sizeof dp[sel]);
    rep(j,0,i){
      rep(num,0,1){
        int w0=dp[sel^1][j][0][num],w1=dp[sel^1][j][1][num];
        int su0,su1,x,tmp;
        su0=calc(A[i]-num,B-num-1);
        su1=calc(0,A[i]-1-num);
        x=A[i]-num;
        tmp=x>=0&&x<=B-num-1?min(x,2*B-2-x)+1:0;
        Add(dp[sel][j][0][0],1ll*su0*w0%P);
        Add(dp[sel][j][1][0],1ll*su1*w0%P);
        Add(dp[sel][j][0][0],1ll*(su0-tmp+P)*w1%P);
        Add(dp[sel][j][1][0],1ll*(su1+tmp)*w1%P);
        if(j>=k){
          if(i<n){
            Add(ans,1ll*calc(!num,B-num-1)*(w0+w1)%P);
          }else{
            Add(ans,(1ll*(su1-(!num))*w0%P+1ll*((su1-!num)+tmp)*w1)%P);
          }
        }
        su0=calc(A[i]-num+B,2*B-2);
        su1=calc(B-num,A[i]-1-num+B);
        x=A[i]-num+B;
        tmp=B-num<=x&&x<=2*B-2?min(x,2*B-2-x)+1:0;
        Add(dp[sel][j+1][0][1],1ll*su0*w0%P);
        Add(dp[sel][j+1][1][1],1ll*su1*w0%P);
        Add(dp[sel][j+1][0][1],1ll*(su0-tmp+P)*w1%P);
        Add(dp[sel][j+1][1][1],1ll*(su1+tmp)*w1%P);
      }
    }
    sel^=1;
  }
  cout<<ans<<endl;
  return 0;
}