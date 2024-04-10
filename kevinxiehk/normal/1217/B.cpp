#include<bits/stdc++.h>
using namespace std;
void solve(){
    double n,x;
    cin>>n>>x;
    priority_queue<int>q;
    int a,b,ma=-1;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ma=max(a,ma);
        q.push(a-b);
    }
    x-=ma;
    double t=q.top();
    if(x>0&&t<=0){cout<<"-1"<<endl;return;}
    if(x<=0){cout<<"1"<<endl;return;}
    int cnt=1;
    cnt+=ceil(x/t);
    //if(x%t!=0)cnt++;
    cout<<cnt<<endl;
    return ;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}