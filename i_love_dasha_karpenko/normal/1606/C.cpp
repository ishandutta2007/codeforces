#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 20;
const int MAXN = 18;
int vis[N];
ll need[N];
void solve(){
   int n,k;
   cin>>n>>k;
   for(int i = 1;i<=n;++i){
       int nom;
       cin>>nom;
       vis[nom] = 1;
   }
   ll sum = 0;
   ll digits = 0,num = 0,mult = 1;
   for(int i = 0;i<=MAXN;++i){
        if (vis[i])
            need[i] = 1;
        else need[i] = need[i-1]*10;
        sum+=need[i]*9;
        num+=mult*9;
        mult*=10;
        if (sum>k){
            digits = i;
            break;
        }
   }
   mult/=10;
   for(int i = digits;i>=0;--i){
       while(sum-need[i]>k)
           num-=mult,sum-=need[i];
       mult/=10;
   }
   cout<<num<<endl;
   memset(vis,0,sizeof(vis));

}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}