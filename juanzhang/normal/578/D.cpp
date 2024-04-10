#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int n,m;char str[100010];

int main(){
  scanf("%d%d%s",&n,&m,str+1);int ct=0,t1=-1,t2=-1,len=0;ll tmp=0;
  rep(i,1,n){
    ct+=str[i]!=str[i-1];
    if(t2==str[i]){
      len++,swap(t1,t2);
    }else t1=str[i],t2=str[i-1],len=i>1;
    if(t1==t2)len=0,t1=-1,t2=-1;
    tmp+=len;
  }
  cout<<1ll*ct*(m-1)*n-tmp<<endl;
  return 0;
}