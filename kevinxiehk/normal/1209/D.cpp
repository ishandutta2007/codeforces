#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
bool ava[100005];
queue<int>idk[100005];
int cnt=0;
pair<int,int>arr[100005];
void dfs(int n){
    ava[n]=0;
    while(!idk[n].empty()){
        int t=idk[n].front();
        idk[n].pop();
        if(ava[t]){
            cnt++;
            dfs(t);
        }
    }
    return;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n+1;i++)ava[i]=1;
    int t,tt;
    for(int i=0;i<k;i++){
        cin>>t>>tt;
        idk[t].push(tt);
        idk[tt].push(t);
    }
    for(int i=1;i<=n;i++){
        if(!ava[i])continue;
        dfs(i);
    }
    cout<<k-cnt<<endl;
    return 0;
}