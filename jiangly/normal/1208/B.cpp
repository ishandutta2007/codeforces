#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int MAX_N=2e3+5;
    int n;
    int a[MAX_N];
    set<int> sp;
public:
    void solve(){
        cin>>n;
        int ans=n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=0;i<=n;++i){
            if(i>0){
                if(sp.count(a[i])){
                    break;
                }
                sp.insert(a[i]);
            }
            set<int> s=sp;
            int r=n+1;
            while(r>i+1&!s.count(a[r-1])){
                s.insert(a[r-1]);
                --r;
            }
            ans=min(ans,r-i-1);
        }
        cout<<ans<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}