#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

vector<int> maximumindependentset(vector<vector<int>>& g){
  int N=g.size();
  //bitDP
  int n1=N/2,n2=N-n1;
  //dp[bit]:bit
  vector<int> dp(1<<n1);
  for(int bit=0;bit<(1<<n1);++bit){
    bool f=true;
    for(int i=0;i<n1;++i)if(bit>>i&1)
    for(int j=0;j<i;++j)if(bit>>j&1){
      if(g[j][i]){
        f=false;
        i=n1;break;
      }
    }
    if(f)dp[bit]=__builtin_popcount(bit);
  }
  for(int i=0;i<n1;++i){
    for(int bit=0;bit<(1<<n1);++bit){
      dp[bit|1<<i]=max(dp[bit],dp[bit|1<<i]);
    }
  }

  int ans=0,ansbit1=0,ansbit2=0;
  for(int bit2=0;bit2<(1<<n2);++bit2){
    bool f=true;
    for(int i=0;i<n2;++i)if(bit2>>i&1)
    for(int j=0;j<i;++j)if(bit2>>j&1){
      if(g[j+n1][i+n1]){
        f=false;
        i=n2;break;
      }
    }
    if(!f)continue;
    int bit=0;
    for(int i=0;i<n1;++i)for(int j=0;j<n2;++j)if(bit2>>j&1){
      if(g[i][j+n1])bit|=1<<i;
    }
    bit=(~bit)&((1<<n1)-1);
    if(ans<__builtin_popcount(bit2)+dp[bit]){
      ans=__builtin_popcount(bit2)+dp[bit];
      ansbit2=bit2;ansbit1=bit;
    }
  }
  while(dp[ansbit1]<__builtin_popcount(ansbit1)){
    for(int i=0;i<n1;++i)if(ansbit1>>i&1){
      if(dp[ansbit1]==dp[ansbit1^(1<<i)]){
        ansbit1^=1<<i;
        break;
      }
    }
  }
  vector<int> res;
  res.reserve(ans);
  for(int i=0;i<n1;++i)if(ansbit1>>i&1)res.emplace_back(i);
  for(int i=0;i<n2;++i)if(ansbit2>>i&1)res.emplace_back(i+n1);
  return res;
}

int main(){
  int n,m;
  cin >> m >> n;
  vector<vector<int>> g(n,vector<int>(n));
 
  for(int i=0;i<n;++i)for(int j=0;j<n;++j)g[i][j]=(i==j);
  {
    //
    int mpcnt=0;
    map<string,int> mp;
    vector<int> bf;
    while(m--){
      int a;
      cin>>a;
      if(a==1){
        for(auto x:bf)for(auto y:bf)if(x!=y)g[x][y]=g[y][x]=1;
        bf.clear();
      }else{
        string s;
        cin>>s;
        if(!mp.count(s))mp[s]=mpcnt++;
        bf.emplace_back(mp[s]);
      }
    }
    for(auto x:bf)for(auto y:bf)if(x!=y)g[x][y]=g[y][x]=1;
  }
  cout<<maximumindependentset(g).size()<<'\n';
}