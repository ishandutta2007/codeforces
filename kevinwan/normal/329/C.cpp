#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
vector<int>g[mn];
vector<vector<int>>c;
bool vis[mn];
void die(){
    printf("-1");
    exit(0);
}
void hail(vector<int>&v){
    if(v.size()<5)assert(0);
    vector<int>w;
    if(v.size()&1)for(int i=0;i<2*v.size();i+=2)w.push_back(v[i%v.size()]);
    else{
        for(int i=0;i<v.size();i+=2)w.push_back(v[i]);
        for(int i=v.size()+1;i>1;i-=2)w.push_back(v[i%v.size()]);
    }
    v=w;
}
void report(vector<int>v,int m){
    for(int i=0;i<m;i++)printf("%d %d\n",v[i],v[i+1]);
    exit(0);
}
vector<int>ad[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!vis[i]&&g[i].size()==1){
            c.push_back({});
            stack<int>s;
            s.push(i);
            while(s.size()){
                int x=s.top();
                s.pop();
                if(vis[x])continue;
                vis[x]=1;
                c.back().push_back(x);
                for(int y:g[x])s.push(y);
            }
        }
    for(int i=1;i<=n;i++)if(!vis[i]){
            c.push_back({});
            stack<int>s;
            s.push(i);
            while(s.size()){
                int x=s.top();
                s.pop();
                if(vis[x])continue;
                vis[x]=1;
                c.back().push_back(x);
                for(int y:g[x])s.push(y);
            }
        }
    sort(c.begin(),c.end(),[](vector<int>a,vector<int>b){return a.size()>b.size();});
    if(n<=2)die();
    if(c.size()==1){
        if(n==3)die();
        if(n==4){
            if(m==4)die();
            printf("%d %d\n%d %d\n%d %d",c[0][1],c[0][3],c[0][3],c[0][0],c[0][0],c[0][2]);
            return 0;
        }
        else{
            hail(c[0]);
            c[0].push_back(c[0][0]);
            report(c[0],m);
        }
    }
    else{
        if(c[0].size()>=5)hail(c[0]);
        if(c[0].size()*2>n&&c[0].size()<=4){
            if(c[0].size()==3){
                if(n==4) {
                    if (m == 3)die();
                    else {
                        printf("%d %d\n%d %d", c[0][0], c[0][2], c[0][2], c[1][0]);
                        return 0;
                    }
                }
                else{
                    if(c.size()==3)c[1].push_back(c[2][0]);
                    vector<int>r={c[0][0],c[1][0],c[0][1],c[1][1],c[0][2]};
                    report(r,m);
                }
            }
            else{
                vector<int>r;
                if(n==5){
                    r={c[0][0],c[0][2],c[1][0],c[0][3],c[0][1]};
                }
                else if (n==6){
                    if(c.size()==3)c[1].push_back(c[2][0]);
                    r={c[0][0],c[0][2],c[1][0],c[0][3],c[0][1],c[1][1]};
                }
                else{
                    for(int i=2;i<c.size();i++)for(int j:c[i])c[1].push_back(j);
                    r={c[0][0],c[1][0],c[0][1],c[1][1],c[0][3],c[1][2],c[0][2],c[0][0]};
                }
                report(r,m);
            }
        }
        int cur=0;
        for(int i=1;i<c.size();i++){
            vector<int>v=c[i];
        for(int x:v){
            ad[cur++].push_back(x);
            if(cur>=c[0].size())cur=0;
        }}
        vector<int>r;
        for(int i=0;i<c[0].size();i++){
            r.push_back(c[0][i]);
            for(int j:ad[i])r.push_back(j);
        }
        r.push_back(r[0]);
        report(r,m);
    }
}