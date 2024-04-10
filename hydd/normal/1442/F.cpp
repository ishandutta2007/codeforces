#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,T,deg[1100],l[1100];
bool e[1100][1100];
vector<int> p,s; queue<int> que;
void topo_sort(){
    for (int i=1;i<=n;i++)
        if (!deg[i]) que.push(i);
    while (!que.empty()){
        int u=que.front(); que.pop();
        p.emplace_back(u);
        for (int v=1;v<=n;v++){
            if (!e[u][v]) continue;
            if (!(--deg[v])) que.push(v);
        }
    }
}
int popc[1100000],tot[1100000],pos[1100000]; vector<int> trans[4];
vector<pii> op1,op2;
void ins(int u,int v){
    e[u][v]=true;
    op1.emplace_back(pii(u,v));
}
void del(int u,int v){
    e[u][v]=false;
    op2.emplace_back(pii(u,v));
}
void update(){
    k=min(n,20);
    for (int i=n-k;i<n;i++) s.emplace_back(p[i]);
    for (int i=0;i<k;i++){
        for (int j=i+1;j<k;j++)
            if (!e[s[i]][s[j]]) ins(s[i],s[j]);
        for (int j=0;j<i;j++)
            if (e[s[i]][s[j]]) del(s[i],s[j]);
    }
    int upperlim=(1<<k)-1;
    for (int s=1;s<=upperlim;s++){
        popc[s]=popc[s>>1]+(s&1);
        if (popc[s]<=3) trans[popc[s]].emplace_back(s);
    }
    for (int i=0;i<n-k;i++){
        ins(p[i],p[i]);
        for (int j=0;j<k;j++)
            if (e[p[i]][s[j]]) l[i]|=(1<<j);
        tot[l[i]]++;
    }
    for (int i=0;i<n-k;i++){
        if (tot[l[i]]>1){
            bool ff=false;
            for (int j=1;j<=3&&!ff;j++)
                for (int sta:trans[j])
                    if (!tot[l[i]^sta]){
                        tot[l[i]]--; tot[l[i]^sta]++; l[i]^=sta;
                        for (int t=0;t<k;t++){
                            if (e[p[i]][s[t]]==1&&((l[i]>>t)&1)==0) del(p[i],s[t]);
                            if (e[p[i]][s[t]]==0&&((l[i]>>t)&1)==1) ins(p[i],s[t]);
                        }
                        ff=true; break;
                    }
            assert(ff);
        }
        pos[l[i]]=p[i]; assert(tot[l[i]]==1);
    }
    for (int s=0;s<=upperlim;s++) assert(tot[s]<=1);
}
void print(){
    assert(op1.size()+op2.size()<=4242);
    cout<<op1.size()+op2.size()<<'\n';
    for (pii v:op1) cout<<'+'<<' '<<v.first<<' '<<v.second<<'\n';
    for (pii v:op2) cout<<'-'<<' '<<v.first<<' '<<v.second<<'\n';
    cout.flush();
}
int query(int x){
    cout<<"? 1\n"<<x<<'\n'; cout.flush();
    static string t; cin>>t;
    if (t[0]=='W') return 1;
    if (t[0]=='D') return 0;
    if (t[0]=='L') return -1;
    return 233;
}
bool print(int x){
    cout<<"! "<<x<<'\n'; cout.flush();
    static string t; cin>>t; return t[0]=='C';
}
int main(){
    cin>>n>>m>>T; int u,v;
    for (int i=1;i<=m;i++){
        cin>>u>>v; deg[v]++;
        e[u][v]=true;
    }
    topo_sort(); update(); print();
    while (T--){
        int ans=-1,sta=0;
        for (int i=0;i<k;i++){
            int tmp=query(s[i]); assert(tmp!=233);
            if (tmp==-1) ans=s[i];
            else if (tmp==1) sta|=(1<<i);
        }
        assert(print(ans==-1?pos[sta]:ans));
    }
    return 0;
}