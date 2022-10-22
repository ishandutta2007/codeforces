#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

inline void startupcpp() noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
}

bool sum[128][200001];
int N,M;
int main(){
  startupcpp();
  cin>>N>>M;
  for(int i=0;i<N;++i){
    int x;
    cin>>x;
    sum[0][x]^=true;
  }
  for(int i=1;i<200001;++i)sum[1][i]=sum[1][i-1]^sum[0][i];
  for(int t=0;t<6;++t){
    const unsigned int maxbit=1<<(t+1);
    for(unsigned int bit=0;bit<maxbit;++bit){
      //L%maxbit=bit
      for(int i=1;i<200001;++i){
        sum[maxbit|bit][i]=sum[maxbit|bit][i-1];
        if(((maxbit-bit+i)&(maxbit-1))>>t){
          sum[maxbit|bit][i]^=sum[0][i];
        }
      }
    }
  }
  cin>>M;
  for(int i=0;i<M;++i){
    int l,r;
    cin>>l>>r;
    bool f=false;
    for(int t=0;t<6;++t){
      const unsigned int maxbit=1<<(t+1);
      const unsigned int now=maxbit|(l&(maxbit-1));
      f|=sum[now][r]^sum[now][l-1];
    }
    for(int t=6;t<18;++t){
      const unsigned int maxbit=1<<t;
      bool ch=false;
      for(int nowl=l+maxbit;nowl<=r;nowl+=maxbit*2){
        ch^=sum[1][min(int(maxbit-1)+nowl,r)]^sum[1][nowl-1];
      }
      f|=ch;
    }
    cout<<"BA"[f];
  }
  cout<<endl;
}