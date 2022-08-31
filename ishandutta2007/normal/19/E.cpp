#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <utility>
#include <cstring>
#include <sstream>
#include <complex>
#include <vector>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define F first
#define S second

using namespace std;
typedef pair<int, int> joft;
typedef complex<double> point;
const int MAX_N = 10 * 1000 + 10;

int n, m;
vector<joft> list[MAX_N];

void input(){
        scanf("%d %d", &n, &m);
         FOR(i, m){
                 int u, v;
                 scanf("%d %d", &u, &v);
                 u--;
                 v--;
                 list[u].PB(joft(v, i + 1));
                 list[v].PB(joft(u, i + 1));
         }
}
vector<int> yal;
int dep[MAX_N];
int odd[MAX_N];
int even[MAX_N];
int par[MAX_N];
vector<int> see;

void dfs(int v, int d){//vertex ,depth
         dep[v] = d;
         see.PB(v);
         FOR(i, SZ(list[v])){
                 int u = list[v][i].F;
                 int e = list[v][i].S;
                 //cerr<<v<<" "<<u<<" "<<dep[v]<<" "<<dep[u]<<endl;
                 if(dep[u]){//if node u already visited
                         int sign = 1;
                         if(dep[u] > dep[v])
                                 sign *= -1;
                         else    if(dep[u] + 1 == dep[v])
                                         continue;
                         if((dep[u] & 1) != (dep[v] & 1))
                                 even[v] += sign;
                         else{
                                 odd[v] += sign;
                                 if(sign == 1)
                                         yal.PB(e);
                         }
                 }else{
                         par[u] = e;
                         dfs(u, d + 1);
                         odd[v] += odd[u];
                         even[v] += even[u];
                 }
         }
 }

int main(){
        input();
         int cnt = 0;
         vector<int> ans;
         FOR(i, n)
                if(!dep[i]){
                         see.clear();
                         int bade = SZ(yal);
                         dfs(i, 1);
                         bade = SZ(yal) - bade;
                         if(!bade)       continue;
                         cnt++;
                         FOR(i, SZ(see)){
                                 //cerr<<(see[i] + 1)<<" "<<odd[see[i]]<<" "<<even[see[i]]<<" "<<(par[see[i]] + 1)<<endl;
                                 if(odd[see[i]] == bade && !even[see[i]])
                                        ans.PB(par[see[i]]);
                         }
                }
         if(cnt > 1){
                 printf("0\n");
                 return 0;
         }
         if(cnt == 0){
                printf("%d\n", m);
                FOR(i, m)
                         printf("%d ", i + 1);
                printf("\n");
                 return 0;
         }
        
         if(SZ(yal) == 1)ans.PB(yal[0]);
         
         printf("%d\n", SZ(ans));
         sort(ans.begin(), ans.end());
         FOR(i, SZ(ans)) printf("%d ", ans[i]);
         printf("\n");
         return 0;
}