#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<N;++i)

int H,W,g[250001];
int id(int x,int y){return x*W+y;}
//4
void solve4(const int a,const int b=0){
  vector<int> ids;
  ids.reserve(4);
  vector<int> ans(W);
  rep(j,W){
    ans[j]=g[id(a,j)];
    if(g[id(a,j)]!=g[id(b,j)])ids.emplace_back(j);
  }
  assert(ids.size()==4);
  //6ok
  for(auto& id1:ids)for(auto& id2:ids){
    if(id1>=id2)continue;
    for(auto p:ids)ans[p]=g[id(a,p)];
    ans[id1]=g[id(b,id1)];ans[id2]=g[id(b,id2)];
    bool f=true;
    rep(i,H){
      int cnt=0;
      rep(j,W)if(g[id(i,j)]!=ans[j])++cnt;
      if(cnt>2){f=false;break;}
    }
    if(f){
      puts("Yes");
      rep(j,W)cout<<ans[j]<<" \n"[j==W-1];
      return;
    }
  }
  puts("No");
}
//3
void solve3(int a,int b=0){
  vector<int> ids;
  ids.reserve(3);
  vector<int> ans(W);
  rep(j,W){
    ans[j]=g[id(a,j)];
    if(g[id(a,j)]!=g[id(b,j)])ids.emplace_back(j);
  }
  assert(ids.size()==3);
  vector<int> cnt(H,0);
  rep(i,H)rep(j,W)if(g[id(a,j)]==g[id(b,j)]&&g[id(a,j)]!=g[id(i,j)])cnt[i]++;
  //2
  rep(t,2){
    for(auto x:ids)ans[x]=g[id(a,x)];
    rep(k,3){
      vector<pair<int,int>> v[2];
      bool f=true;
      pair<int,int> anspair;
      rep(i,H){
        int nowcnt=cnt[i]+(g[id(i,ids[k])]!=ans[ids[k]]);
        if(nowcnt>2){
          f=false;
          break;
        }
        if(nowcnt)v[nowcnt-1].emplace_back(g[id(i,ids[(k+1)%3])],g[id(i,ids[(k+2)%3])]);
      }
      while(f){
        rep(i,2){
          sort(v[i].begin(),v[i].end());
          v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
        }
        if(v[1].size()>1){
          f=false;
          break;
        }
        if(v[1].size()){
          anspair=v[1][0];
          for(auto x:v[0]){
            if(x.first!=v[1][0].first&&x.second!=v[1][0].second){
              f=false;
              break;
            }
          }
          break;
        }
        assert(v[0].size());
        map<int,vector<int>> mp;
        for(auto x:v[0])mp[x.first].emplace_back(x.second);
        if(mp.size()==1){
          anspair=v[0][0];
          break;
        }
        vector<pair<int,vector<int>>> check;
        check.reserve(mp.size());
        for(auto x:mp)check.emplace_back(x);
        sort(check.begin(),check.end(),[](auto l,auto r){return l.second.size()>r.second.size();});
        if(check[1].second.size()==1){
          anspair=pair<int,int>(check[0].first,check[1].second[0]);
          for(size_t i=2;i<check.size();++i){
            if(check[i-1].second[0]!=check[i].second[0]){
              f=false;
              break;
            }
          }
        }else f=false;
        break;
      }
      if(f){
        puts("Yes");
        tie(ans[ids[(k+1)%3]],ans[ids[(k+2)%3]])=anspair;
        rep(j,W)cout<<ans[j]<<" \n"[j==W-1];
        return;
      }
    }
    swap(a,b);
  }
  puts("No");
}
int main(){
  cin>>H>>W;
  rep(i,H)rep(j,W)cin>>g[id(i,j)];
  rep(i,H){
    int cnt=0;
    rep(j,W)if(g[id(i,j)]!=g[id(0,j)])++cnt;
    if(cnt>4){
      puts("No");
      return 0;
    }
    if(cnt>2){
      if(cnt==4)solve4(i);
      else solve3(i);
      return 0;
    }
  }
  puts("Yes");
  rep(j,W)cout<<g[id(0,j)]<<" \n"[j==W-1];
}