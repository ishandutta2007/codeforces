#include<bits/stdc++.h>
#define pii pair<int,int>
#define nfs ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lli long long int
using namespace std;
const int INF = 1e9+9,MOD=1e9+7,MOD1=998244353;
const lli INFF = 9e18;
const int N=2e5+1;
struct DSU{
    int par[N]{0},height[N]{0};
    DSU(int n){
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int get(int v){
        return par[v]= (par[v]==v ? v : get(par[v]));
    }
    void join(int a,int b){
        a=get(a);
        b=get(b);
        if(a==b)return;
        if(height[a]>=height[b]){
            par[b]=a;
            if(height[a]==height[b])height[a]++;
        }else{
            par[a]=b;
        }
    }
    void clear(int n){
        for(int i=0;i<=n;i++)par[i]=i,height[i]=0;
    }

};



int main (){
    nfs; 
    int t;  cin>>t;
    while(t--){
        int n,p; cin>>n>>p;

        DSU d1(n);
        vector<int> a=vector<int>(n);
        for(int &x:a)cin>>x;
        vector<pair<int,int>> edges;
        for(int i=0;i<n;i++){
            edges.push_back({a[i],i});
        }
        sort(edges.begin(),edges.end());
        
        lli ans=0ll; 

        for(int i=0;i<edges.size();i++){
            int enow=edges[i].first;
            int vnow=edges[i].second;

            if(enow>=p)break;
            // look back
            while(vnow>0){
                if(a[vnow-1]%enow==0){
                    if(d1.get(vnow-1)!=d1.get(edges[i].second)){
                        d1.join(vnow-1,edges[i].second);
                        ans+=enow*1ll;
                        // cout<<"{"<<enow<<"}";
                    }else break;
                }else break;
                vnow--;
            }
            vnow=edges[i].second;
            // look front
            while(vnow<n-1){
                if(a[vnow+1]%enow==0){
                    if(d1.get(vnow+1)!=d1.get(edges[i].second)){
                        d1.join(vnow+1,edges[i].second);
                        ans+=enow*1ll;
                        // cout<<"{"<<enow<<"}";
                    }else break;
                }else break;
                vnow++;
            }
        }
        set<int>s1;
        for(int i=0;i<n;i++)s1.insert(d1.get(i));
        cout<<ans + 1ll*(s1.size()-1)*p<<endl;
    }
}