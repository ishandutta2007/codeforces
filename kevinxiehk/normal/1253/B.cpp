#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int main(){
    queue<int>ans;
    int cnt=0;
    bool em[1000005];
    int last[1000005];
    for(int i=0;i<=1000000;i++){em[i]=false;last[i]=-100;}
    int n;
    int t;bool b;
    cin>>n;
    int in=0;
    int sofar=-1;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t<0)b=1;else b=0;
        if(b)in--;else in++;
        t=abs(t);
        if(em[t]!=b){cout<<"-1"<<endl;return 0;}
        if(!b&&last[t]>sofar){cout<<"-1"<<endl;return 0;}
        if(em[t])em[t]=0;
        else em[t]=1;
        last[t]=i;
        if(in==0){
            cnt++;
            ans.push(i-sofar);
            sofar=i;
        }
    }
    if(in!=0){cout<<"-1"<<endl;return 0;}
    cout<<cnt<<endl;
    while(!ans.empty()){cout<<ans.front()<<" ";ans.pop();}
    return 0;
}