#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<string.h>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#define MX 1020
#define INF 99999999
using namespace std;

int num ,n ,k;
vector<int> G[MX];
int d[MX*MX] ,g[MX][MX] ,vis[MX];
struct node{
    int x ,y;
}point[MX];
bool dfs(int cnt ,int m){// cnt  m 
    if(cnt > n)  return true;
    if(vis[cnt])    return dfs(cnt + 1 ,m);
    for(int i = 0;i < (int)G[cnt].size(); i++){
         m += !vis[G[cnt][i]];
         vis[G[cnt][i]]++;
    }
    if(m <= k && dfs(cnt + 1 ,m))
               return true;
    int temp = m;
    for(int i = 0;i < (int)G[cnt].size(); ++i){
        vis[G[cnt][i]]--;
        m -= !vis[G[cnt][i]];
    }
    if(G[cnt].size() != 1){
        vis[cnt]++;
        if(m + 1 <= k && m + 1 < temp && dfs(cnt+1 ,m+1))
            return true;
        vis[cnt]--;
    }
    return false;
}
bool judge(int dist){
    memset(vis ,false ,sizeof(vis));
    for(int i = 1;i <= n;i++)
         G[i].clear();
    for(int i = 1;i < n;i++)
      for(int j = i+1;j <= n;j++)
          if(g[i][j] > dist){
              G[i].push_back(j);
              G[j].push_back(i);
          }
    return  dfs(1 ,0);
}
int binary_search(int le ,int rt){
    int mid;
    while(le < rt){
       mid = (le + rt)>>1;
       if(judge(d[mid]))  rt = mid;
       else  le = mid + 1;
    }
    return le;
}
int main(){
    //freopen("g.txt" ,"r" ,stdin);
    scanf("%d%d" ,&n ,&k);
    num = 0; d[0] = 0;
    for(int i = 1;i <= n; i++)
       scanf("%d%d" ,&point[i].x ,&point[i].y);
    for(int i = 1;i < n; i++)
      for(int j = i+1;j <= n; j++)
        d[++num] = g[i][j] = (point[i].x-point[j].x)*(point[i].x-point[j].x) + (point[i].y - point[j].y)*(point[i].y-point[j].y);
    sort(d ,d + num + 1);
    num = unique(d ,d+num+1) - d - 1;
    int mx = binary_search(0 ,num); //   
    judge(d[mx]);
    for(int i = n;i >= 1; i--)
      if(vis[i]){
          printf("%d " ,i);
          k--;
      }
    for(int i = n;i >= 1 && k > 0; i--)
       if(!vis[i]){
           printf("%d " ,i);
           k--;
       }
    cout<<endl;
    
    return 0;
}