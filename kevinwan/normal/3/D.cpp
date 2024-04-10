#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll lowinf=1e14;
ll p[mn];
struct comp{
    bool operator()(int&a,int&b){return p[a]>p[b];}
};
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    int i;
    cin>>s;
    int n=s.size();
    ll ans=0,a,b;
    for(i=0;i<n;i++){
        if(s[i]=='(')ans+=lowinf,p[i]=-lowinf;
        else if(s[i]==')')p[i]=lowinf;
        else{
            cin>>a>>b;
            ans+=b;
            p[i]=a-b;
        }
    }
    int ch=0;
    string pr;
    for(i=0;i<n;i++)pr.push_back(')');
    priority_queue<int,vector<int>,comp>pq;
    for(i=0;i<n;i++){
        pq.push(i);
        if(!(i&1)){
            int u=pq.top();
            pq.pop();
            ans+=p[u];
            pr[u]='(';
        }
    }
    if(ans>=lowinf/2)printf("-1");
    else{
        printf("%lld\n%s",ans,pr.c_str());
    }

}