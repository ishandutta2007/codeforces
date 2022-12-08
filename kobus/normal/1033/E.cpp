#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<long long,long long>
#define MAXN 2123456
#define INF LLONG_MAX
#define double long double
#define pi acos(-1)
#define MOD 1000000007 
#define eps 1e-7
#define int long long
 
 
int ask(vector<int> &v){
    if(v.size()==0)return 0;
    if(v.size()==1)return 0;
    cout<<'?'<<" "<<v.size()<<"\n";
    for(auto x:v){
        cout<<x+1<<" ";
    }
    cout<<endl;
    int x;
    cin>>x;
    if(x==-1)assert(0);
    return x;
}
 
int conecta(int a,vector<int> &v){
    /*cout<<"conecta "<<a<<" ";
    for(auto x:v)cout<<x<<" ";
    cout<<endl;*/
    v.pb(a);
    int r1=ask(v);
    v.pop_back();
    if(r1==0)return 0;
    int r2=ask(v);
    return r1-r2;
}
 
int find_first_edge(int a,vector<int> &v,int i,int j){
    /*cout<<"ffe "<<a<<" "<<i<<" "<<j<<" ";
    for(auto x:v)cout<<x<<" ";
    cout<<endl;*/
    if(i==j)return i;
    int meio=(i+j)/2;
    vector<int> vv;
    for(int k=i;k<=meio;k++)vv.pb(v[k]);
    if(conecta(a,vv)>0)return find_first_edge(a,v,i,meio);
    return find_first_edge(a,v,meio+1,j);
}
 
vector<int> adj(int a,vector<int> v){
    vector<int> resp;
    int edges=conecta(a,v);
    int ind=-1;
    for(int i=0;i<edges;i++){
        ind=find_first_edge(a,v,ind+1,v.size()-1);
        resp.pb(v[ind]);
    }
    return resp;
}
 
int h[1123];
int pai[1123];
bool cor[1123];
vector<int> are[1123];
set<int> aa;
 
void dfs(int u){
    //cout<<u<<endl;
    vector<int> left;
    for(auto x:aa)left.pb(x);
    are[u]=adj(u,left);
    for(auto x:are[u]){
        aa.erase(x);
        cor[x]=!cor[u];
        h[x]=h[u]+1;
        pai[x]=u;
    }
    for(auto x:are[u]){
        dfs(x);
    }
}
 
pii acha_par(vector<int> &v){
    for(int i=v.size()-1;i>=0;i--){
        int x=v[i];
        v.pop_back();
        if(conecta(x,v)>0){
            int y=find_first_edge(x,v,0,v.size()-1);
            return mp(x,v[y]);
        }
    }
}
vector<int> are2[1123];
vector<int> caminho;
 
bool fcaminho(int u,int d,int p){
    //cout<<u<<" "<<d<<" "<<p<<endl;
    caminho.pb(u+1);
    if(u==d)return 1;
    for(auto x:are2[u]){
        if(x!=p && fcaminho(x,d,u))return 1;
    }
    caminho.pop_back();
    return 0;
}
 
int32_t main () {
 
    int n;
    cin>>n;
    for(int i=n-1;i>=0;i--){
        aa.insert(i);
    }
    for(int i=0;i<n;i++){
        if(aa.find(i)!=aa.end()){
            aa.erase(i);
            dfs(i);
        }
    }
    vector<int> fs;
    vector<int> ss;
    for(int i=0;i<n;i++){
        if(cor[i]==0)fs.pb(i);
        else ss.pb(i);
    }
    if(ask(ss)==0){
        if(ask(fs)==0){
            cout<<"Y "<<ss.size()<<"\n";
            for(auto x:ss)cout<<x+1<<" ";
            cout<<endl;
            return 0;
        }
        else{
            ss=fs;
        }
    }
    for(int i=0;i<n;i++){
        for(auto x:are[i]){
            are2[i].pb(x);
            are2[x].pb(i);
            //cout<<"are "<<i<<" "<<x<<endl;
        }
    }
    //cout<<"ss"<<endl;
    //for(auto x:ss)cout<<x<<" ";
    //cout<<endl;
    pii par=acha_par(ss);
    //cout<<"par "<<par.f<<" "<<par.s<<endl;
    fcaminho(par.f,par.s,par.f);
    cout<<"N "<<caminho.size()<<"\n";
    for(auto x:caminho)cout<<x<<" ";
    cout<<endl;
 
    
    return 0;
}