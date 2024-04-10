#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=1e5+10,inf=2e9;
int n;
struct node{
  int x,y;
}A[maxn];
vector<int>X,Y;

int main(){
  cin>>n;long long ans=0;
  rep(i,1,n)scanf("%d%d",&A[i].x,&A[i].y),X.push_back(A[i].x),Y.push_back(A[i].y);
  sort(X.begin(),X.end()),sort(Y.begin(),Y.end());int mid=(n-1)/2;rep(i,0,mid)ans-=X[i]+Y[i];rep(i,mid+(~n&1),n-1)ans+=X[i]+Y[i];ans*=2;
  int ct=0,c24=0,c13=0;rep(i,1,n){
    if(n%2==1&&ct<=1&&(A[i].x==X[mid]||A[i].y==Y[mid])){
      ct++;
    }else if((A[i].x<=X[mid])^(A[i].y<=Y[mid])){
      c24++;
    }else{
      c13++;
    }
//    }else if((A[i].x<=X[mid]&&A[i].y>=Y[mid])||(A[i].x>=X[mid]&&A[i].y<=Y[mid])){
//      c24++;
//    }
  }
  if(ct>1||!c24||!c13)return cout<<ans<<endl,0;
  ans+=2*max(max(X[mid]-X[mid+1],n&1?X[mid-1]-X[mid]:-inf),max(Y[mid]-Y[mid+1],n&1?Y[mid-1]-Y[mid]:-inf)),cout<<ans<<endl;
  return 0;
}