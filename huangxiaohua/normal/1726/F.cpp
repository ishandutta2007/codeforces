#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int inf = 1e18;
using type = tuple<int,int,int>;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, T, S=0;
    cin >> N >> T; N++;
    vector<int>o(N), g(N), t(N);
    for(int i=0;i<N-1;i++) cin>>g[i]>>o[i];
    for(int i=1;i<N-1;i++) cin>>t[i];
    
    auto get = [&](int v){
        v%=T; if(v<0)v+=T;
        return v;
    };
     
    vector<int>s(N),e(N),nxt(N);
    priority_queue<type,vector<type>,greater<>>pq;
    set<pair<int,int>>idx;
    for(int i=0;i<N;i++){
        S+=t[i];
        s[i] = get(-o[i]-S);
        e[i] = get(-o[i]-S+g[i]);
        swap(s[i], e[i]);
        
        if(i!=N-1)pq.push({get(s[i]-1),1,-1});
        else{
            s[i]=-1;
            e[i]=T;
        }
        
        vector<pair<int,int>>rm;
        auto st = idx.lower_bound({s[i],-inf});
        auto et = idx.lower_bound({e[i],-inf});
        if(s[i]<e[i]){
            pq.push({s[i],0,i});
            pq.push({e[i],2,i});
            for(;st!=et;++st){
                nxt[st->second]=i;
                rm.push_back(*st);
            }
        }
        else{
            pq.push({s[i],0,i});
            pq.push({T-1,2,i});
            pq.push({0,0,i});
            pq.push({e[i],2,i});
            for(;st!=idx.end();++st){
                nxt[st->second]=i;
                rm.push_back(*st);
            }
            st = idx.begin();
            for(;st!=et;++st){
                nxt[st->second]=i;
                rm.push_back(*st);
            }
        }
        for(auto &i:rm)idx.erase(i);
        if(i!=N-1)idx.insert({e[i],i});
    }
    assert(idx.empty());
    
    nxt[N-1]=0;
    for(int i=N-2;i>=0;i--){
        int j = nxt[i];
        nxt[i]=nxt[j];
        if(j!=N-1){
            nxt[i]+=e[j]-e[i];
            if (s[j]>e[j] && e[i]>=s[j]) nxt[i]+=T;
        }
    }
    
    int ans = inf, i, tp, y;
    set<int>ids;
    while(!pq.empty()){
        tie(y,tp,i)=pq.top();pq.pop();
        if(tp==0)ids.insert(i);
        else if(tp==2)ids.erase(i);
        else {
            i = *ids.begin();
            if(i==N-1)ans=0;
            else if(s[i]<e[i])ans=min(ans,nxt[i]+e[i]-y);
            else{
                if(y>=s[i])ans=min(ans,nxt[i]+e[i]+T-y);
                else ans=min(ans,nxt[i]+e[i]-y);
            }
        }
    }
    cout<<ans+S<<endl;
}