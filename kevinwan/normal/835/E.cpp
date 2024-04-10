#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=3e5+10;
int n,x,y;
int ask(int msk){
    vector<int>l;
    for(int i=1;i<=n;i++)if((i&msk)==msk)l.push_back(i);
    if(!l.size())return 0;
    cout<<"? "<<l.size();
    for(int x:l)cout<<" "<<x;
    cout<<endl;
    int v;
    cin>>v;
    if(v==-1)exit(0);
    return v==y||v==(x^y);
}
int main() {
    cin>>n>>x>>y;
    int xo=0;
    for(int i=0;i<10;i++)xo|=ask(1<<i)<<i;
    int peg=0;
    for(int i=0;i<10;i++)if((xo>>i)&1){
        peg=i;
        break;
    }
    int ans=1<<peg;
    for(int i=0;i<10;i++)if(i!=peg){
        ans|=ask((1<<peg)|(1<<i))<<i;
    }
    int ans2=xo^ans;
    if(ans>ans2)swap(ans,ans2);
    cout<<"! "<<ans<<' '<<ans2<<endl;
}