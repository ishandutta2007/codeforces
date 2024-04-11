#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define mp make_pair
#define ld long double
#define MOD 998244353 
#define MAXN 512345
 
 
int dis[1123456];
 
int32_t main(){
 
 
    int n;
    cin>>n;
    vector<int> hand;
    vector<int> table;
 
    int znm=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0)znm++;
        hand.pb(x);
    }
    if(znm==0){
        cout<<n<<endl;
        return 0;
    }
 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        table.pb(x);
    }
    int resp=0;
    int n0=0;
 
    set<int> hands;
    for(auto x:hand)if(x!=0)hands.insert(x);
    int draw=0;
    int ult=table[n-1];
    for(int i=n-2;i>=0;i--){
        if(table[i]==0||table[i]!=table[i+1]-1)break;
        else ult=table[i];
    }
    if(table[n-1]!=0 && ult==1){
        int nxt=table[n-1]+1;
        bool deu=1;
        while(nxt<=n){
            if(hands.find(nxt)==hands.end()){
                deu=0;
                break;
            }
            else{
                hands.erase(nxt);
                nxt++;
                hands.insert(table[draw]);
                draw++;
            }
        }
        if(deu){
            cout<<n-(table[n-1])<<endl;
            return 0;
        }
    }
 
    for(int i=0;i<n;i++){
        if(table[i]==0)continue;
        dis[table[i]]=(i+1)+(n-table[i]+1);
        resp=max(resp,dis[table[i]]);
    }
    for(int i=0;i<n;i++){
        if(hand[i]==0)continue;
        dis[hand[i]]=(n-hand[i]+1);
        resp=max(resp,dis[hand[i]]);
    }
    cout<<resp<<endl;
 
    
    return 0;
}