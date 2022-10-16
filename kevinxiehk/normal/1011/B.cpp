/* bread
  _______
   /       )
  /_____   | ______
 (  '   ) / /    __\   _____
  |.  '| / |     \ |  /     ))
  |____|/  |`-----'  /_____))
            \`-----'  `------' */
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>m>>n;
    int arr[n+5];
    int cnt[105];
    for(int i=0;i<=100;i++)cnt[i]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    int can=1;
    bool poss=true;
    while(poss){
        int t=0;
        for(int i=0;i<=100;i++)t+=cnt[i]/can;
        if(t<m){cout<<can-1<<endl;return 0;}
        can++;
    }
    return 0;
}