#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,A[2021];

int main(){
  int T;cin>>T;while(T--){
    cin>>n;
    int ct=0;
    vector<int>vec;
    rep(i,1,n){
      scanf("%d",A+i);
      if(A[i]%2==0){
        ct++;
      }else{
        vec.push_back(A[i]);
      }
    }
    int ans=1ll*ct*(ct-1)/2+ct*(n-ct);
    rep(i,0,vec.size()-1)rep(j,i+1,vec.size()-1){
      ans+=__gcd(vec[i],vec[j])>1;
    }
    cout<<ans<<endl;
  }
  return 0;
}