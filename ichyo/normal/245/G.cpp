#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
map<string, int> name_id;
string id_to_name[10000];
int get_id(string s){
  if(name_id.count(s)) return name_id[s];
  int id = name_id.size();
  id_to_name[id] = s;
  return name_id[s] = id;
}

int main(){
  int M;
  cin>>M;
  vector<int> friends[10000];
  set<int> is_friend[10000];
  REP(i, M){
    string s, t; cin>>s>>t;
    int x = get_id(s);
    int y = get_id(t);
    if(is_friend[x].count(y)) continue;
    friends[x].push_back(y);
    is_friend[x].insert(y);
    friends[y].push_back(x);
    is_friend[y].insert(x);
  }
  int N = name_id.size();
  cout<<N<<endl;
  FORIT(it, name_id){
    string name = it->first;
    int id = it->second;
    vector<int> cnt(N);
    int num_suggest = 0;
    int max_cnt = 0;
    REP(i, friends[id].size()){
      int f_id = friends[id][i];
      REP(j, friends[f_id].size()){
        int ff_id = friends[f_id][j];
        if(ff_id == id) continue;
        if(is_friend[id].count(ff_id)) continue;
        cnt[ff_id]++;
        if(cnt[ff_id] > max_cnt){
          num_suggest = 1;
          max_cnt = cnt[ff_id];
        }else if(cnt[ff_id] == max_cnt){
          num_suggest++;
        }
      }
    }
    if(num_suggest == 0){
      num_suggest = N - 1 - friends[id].size();
    }
    printf("%s %d\n", name.c_str(), num_suggest);
  }
  return 0;
}