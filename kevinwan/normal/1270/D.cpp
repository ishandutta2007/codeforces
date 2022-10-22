#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
set<int>s;
pii query(){
    printf("?");
    for(int x:s)printf(" %d",x);
    printf("\n");
    fflush(stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    return {a,b};
}
vector<pii>v;
map<int,int>m;
int sid[600];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==1){
        cout<<"! 1"<<endl;
        return 0;
    }
    for(int i=1;i<=k-1;i++)s.insert(i);
    pii ln;
    for(int i=k;i<=n;i++){
        s.insert(i);
        pii p=query();
        v.push_back({p.second,p.first});
        s.erase(p.first);
        ln=p;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)m[v[i].second]=i;
    s.clear();
    vector<int>rem;
    for(int i=1;i<=n;i++)if(m.find(i)==m.end())rem.push_back(i);
    for(int i=1;i<rem.size();i++)s.insert(rem[i]);
    s.insert(v[0].second);
    s.insert(v[1].second);
    ln=query();
    sid[rem[0]]=1;
    int num=1;
    for(int i=1;i<rem.size();i++){
        s.insert(rem[i-1]);
        s.erase(rem[i]);
        pii p=query();
        if(p==ln)sid[rem[i]]=1,num++;
        else sid[rem[i]]=0;
    }
    int onum=n-num-v.size();
    if(m[ln.first]==1)printf("! %d\n",num+1);
    else printf("! %d\n",onum+1);
    fflush(stdout);
    return 0;
}