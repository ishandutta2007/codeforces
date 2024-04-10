#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n;
queue<pair<int,int>>ans;
vector<int>same;
void comb(int l,int r){
    int t=r-l+1;
    for(int i=0;i<t;i++){
        ans.push(mp(same[i],i+l));
    }
    for(int i=l;i<=r;i++)same.pb(i);
    return;
}
void solve(){
    int n;cin>>n;
    int gap=2;
    while(gap<=n){
        for(int i=1;i+gap<=n+1;i+=gap){
            for(int j=i;j<i+gap/2;j++)ans.push(mp(j,j+gap/2));
        }
        gap*=2;
    }
    int l=1,r=n;
    int nn=n;
    queue<int>todo;
    for(int tim=2;tim<=n;tim*=2){
        if(n%tim!=0){
            todo.push(tim/2);
            n-=tim/2;
        }
    }
    if(todo.empty()){
        cout<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.front().fi<<" "<<ans.front().se<<endl;
            ans.pop();
        }
        return;
    }
    int t=todo.front();
    todo.pop();
    for(int i=1;i<=t;i++)same.pb(i);
    l=t+1;
    comb(r-t+1,r);
    r-=t;
    n=nn;
    int last=t*2;
    while(!todo.empty()){
        int a=todo.front();
        while(a>last){
            comb(l,l+last-1);
            l+=last;
            last*=2;
        }
        comb(r-a+1,r);
        r-=a;
        last*=2;
        todo.pop();
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.front().fi<<" "<<ans.front().se<<endl;
        ans.pop();
    }
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    //cin>>t;
    
    while(t--)solve();
    return 0;
}