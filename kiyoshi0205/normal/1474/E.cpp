#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    int N;
    cin>>N;
    long long mid=N/2,ans=mid*mid;
    vector<int> v(N),a,b;
    a.reserve(N-1);b.reserve(N-1);
    for(int i=0;i<N;++i)v[i]=i+1;

    a.emplace_back(mid+1);
    b.emplace_back(1);
    swap(v[0],v[mid]);

    for(long long i=N-1;i>0;--i){
      if(i<mid){
        ans+=(N-1-i)*(N-1-i);
        a.emplace_back(i+1);
        b.emplace_back(N);
        swap(v[i],v[N-1]);
      }else if(i>mid){
        ans+=i*i;
        a.emplace_back(i+1);
        b.emplace_back(1);
        swap(v[i],v[0]);
      }
    }

    cout<<ans<<"\n";
    for(int i=0;i<N;++i)cout<<v[i]<<" \n"[i==N-1];
    cout<<N-1<<"\n";
    for(int i=N-2;i>=0;--i)cout<<a[i]<<" "<<b[i]<<"\n";
  }
}