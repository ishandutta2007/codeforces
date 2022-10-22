#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
mt19937 rng(time(0));
ll h[mn],p[mn];
inline ll hsh(int a,int b){
    if(!a)return h[b];
    else return h[b]-h[a-1]*p[b-a+1];
}
string s;
struct comp{
    inline bool operator()(pii a,pii b){
        int l=min(a.second-a.first,b.second-b.first);
        int cur=-1;
        for(int i=1<<16;i;i>>=1){
            if(cur+i>l)continue;
            if(hsh(a.first,a.first+cur+i)==hsh(b.first,b.first+cur+i))cur+=i;
        }
        if(cur==l)return a.second-a.first>b.second-b.first;
        return s[a.first+cur+1]>s[b.first+cur+1];
    }
};
int main()
{
    cin>>s;
    int k,i;
    scanf("%d",&k);
    p[1]=rng()*2LL+1;
    p[0]=1;
    h[0]=s[0];
    for(i=1;i<s.size();i++){
        h[i]=h[i-1]*p[1]+s[i];
        p[i]=p[i-1]*p[1];
    }
    priority_queue<pii,vector<pii>,comp>pq;
    for(i=0;i<s.size();i++)pq.push({i,i});
    k--;
    comp()({0,1},{1,1});
    while(k--){
        if(!pq.size())break;
        pii p=pq.top();
        pq.pop();
        if(p.second!=s.size()-1)pq.push({p.first,p.second+1});
    }
    if(!pq.size())printf("No such line.");
    else{
        pii p=pq.top();
        for(i=p.first;i<=p.second;i++)printf("%c",s[i]);
    }
}