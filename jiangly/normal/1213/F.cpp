#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=200005;
int n,k;
int p[MAX_N],q[MAX_N],piq[MAX_N],pi[MAX_N];
string sp;
class State{
public:
    int mn;
    int mx;
    int len;
    State(int mn,int mx,int len):mn(mn),mx(mx),len(len){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>p[i];
    }
    for(int i=1;i<=n;++i){
        cin>>q[i];
    }
    for(int i=1;i<=n;++i){
        pi[p[i]]=i;
    }
    for(int i=1;i<=n;++i){
        piq[i]=pi[q[i]];
    }
    vector<State> stk;
    for(int i=1;i<=n;++i){
        State cur(piq[i],piq[i],1);
        while(!stk.empty()&&cur.mn<=stk.back().mx){
            cur.mn=min(cur.mn,stk.back().mn);
            cur.mx=max(cur.mx,stk.back().mx);
            cur.len+=stk.back().len;
            stk.pop_back();
        }
        stk.push_back(cur);
    }
    if(stk.size()>=k){
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;++i){
            for(int j=1;j<=stk[i].len;++j){
                sp+='a'+i;
            }
        }
        while(sp.length()<n){
            sp+='a'+k-1;
        }
        for(int i=1;i<=n;++i){
            cout<<sp[pi[i]-1];
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}