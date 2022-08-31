#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=1e6+5;
    static constexpr int INF=1e9;
    int n,w,l;
    int a[MAX_N];
    LL ans[MAX_N]={};
    LL d[MAX_N]={};
    int pre[MAX_N];
    int suf[MAX_N];
public:
    void solve(){
        cin>>n>>w;
        for(int k=1;k<=n;++k){
            cin>>l;
            for(int i=1;i<=l;++i){
                cin>>a[i];
            }
            if(l*2>=w){
                deque<int> que;
                for(int i=1;i<=w;++i){
                    if(!que.empty()&&que.front()<i+l-w){
                        que.pop_front();
                    }
                    if(i<=l){
                        while(!que.empty()&&a[i]>=a[que.back()]){
                            que.pop_back();
                        }
                        que.push_back(i);
                    }
                    if(i>l||i<=w-l){
                        ans[i]+=max(0,a[que.front()]);
                    }else{
                        ans[i]+=a[que.front()];
                    }
                }
            }else{
                pre[0]=-INF;
                suf[l+1]=-INF;
                for(int i=1;i<=l;++i){
                    pre[i]=max(pre[i-1],a[i]);
                }
                for(int i=l;i>=1;--i){
                    suf[i]=max(suf[i+1],a[i]);
                }
                for(int i=1;i<l;++i){
                    ans[i]+=max(0,pre[i]);
                }
                for(int i=w-l+2;i<=w;++i){
                    ans[i]+=max(0,suf[i+l-w]);
                }
                d[l]+=max(0,pre[l]);
                d[w-l+2]-=max(0,pre[l]);
            }
        }
        for(int i=2;i<=w;++i){
            d[i]+=d[i-1];
        }
        for(int i=1;i<=w;++i){
            cout<<ans[i]+d[i]<<' ';
        }
        cout<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}