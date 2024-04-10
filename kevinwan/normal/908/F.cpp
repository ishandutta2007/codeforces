#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=3e5+10;
int main(){
    int n;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    int lg=-1,ans=0;
    vector<int>r,b;
    for(int i=1;i<=n;i++){
        string s;
        int p;
        cin>>p>>s;
        char c=s[0];
        if(c=='R')r.push_back(p);
        else if(c=='B')b.push_back(p);
        else{
            int ad=0;
            if(lg==-1){
                if(r.size())ad+=p-r[0];
                if(b.size())ad+=p-b[0];
            }
            else{
                int cb=0,cr=0;
                r.insert(r.begin(),lg);
                r.push_back(p);
                b.insert(b.begin(),lg);
                b.push_back(p);
                for(int i=0;i+1<r.size();i++)cr=max(cr,r[i+1]-r[i]);
                for(int i=0;i+1<b.size();i++)cb=max(cb,b[i+1]-b[i]);
                ad=min(2LL*(p-lg),3LL*(p-lg)-cr-cb);
            }
            ans+=ad;
            lg=p;
            r.clear();
            b.clear();
        }
    }
    if(r.size())ans+=r.back()-lg;
    if(b.size())ans+=b.back()-lg;
    if(lg==-1){
        ans=0;
        if(r.size())ans+=r.back()-r[0];
        if(b.size())ans+=b.back()-b[0];
    }
    printf("%d",ans);
}