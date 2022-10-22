#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);


int ct=0;
int col[mn];
int p[mn],nd[mn];
vector<int>rel[mn];
vector<int>g[mn],rg[mn],rnd[mn];
vector<int>v;
vector<vector<int> >ans[2];
vector<int>rd[2];
int main(){
    #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    v.resize(6*n);
    iota(v.begin(),v.end(),0);
    //cerr<<"check"<<endl;
    for(int i=1;i<=3*n;i++){
        int x;
        cin>>x;
        //cerr<<x<<endl;
        p[x-1]=1;
    }
    while(v.size()){
        for(int i=0;i+3<=v.size();i++){
            if(p[v[i+2]]==p[v[i]]&&p[v[i+1]]==p[v[i]]){
                //cerr<<v[i]<<' '<<v[i+1]<<' '<<v[i+2]<<endl;
                if(i)rel[v[i-1]].push_back(ct);
                col[ct]=p[v[i]];
                for(int y:rel[v[i]])g[ct].push_back(y),rg[y].push_back(ct);
                for(int y:rel[v[i+1]])g[ct].push_back(y),rg[y].push_back(ct);
                rnd[ct]={v[i],v[i+1],v[i+2]};
                nd[v[i+2]]=nd[v[i+1]]=nd[v[i]]=ct++;
                v.erase(v.begin()+i,v.begin()+i+3);
                //cerr<<v.size()<<endl;
                break;
            }
        }
    }
    for(int i=0;i<ct;i++){
        if(rg[i].size()==0)rd[col[i]].push_back(i);
    }
    bool turn=0;
    while(rd[turn].size()){
        int x=rd[turn][0];
        for(int i=0;i<rd[turn].size();i++){
            int xx=rd[turn][i];
            bool av=0;
            for(int y:g[xx])av|=(col[y]!=turn);
            if(av){x=xx;rd[turn].erase(rd[turn].begin()+i);break;}
        }
        if(rd[turn].size()&&x==rd[turn][0])rd[turn].erase(rd[turn].begin());
        ans[turn].push_back(rnd[x]);
        cerr<<x<<endl;
        for(int y:g[x]){
            cerr<<x<<' '<<y<<endl;
            assert(rg[y].size());
            rg[y].pop_back();
            if(rg[y].size()==0)rd[col[y]].push_back(y);
        }
        turn^=1;
    }
    for(int i=ans[0].size()-1;i>=0;i--){
        printf("%d %d %d\n%d %d %d\n",ans[1][i][0]+1,ans[1][i][1]+1,ans[1][i][2]+1,ans[0][i][0]+1,ans[0][i][1]+1,ans[0][i][2]+1);
    }
}