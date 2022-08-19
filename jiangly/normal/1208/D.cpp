#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=2e5+5;
    int n;
    int p[MAX_N];
    LL s[MAX_N];
    LL a[MAX_N]={};
    void add(int x,int y){
        while(x<=n){
            a[x]+=y;
            x+=x&-x;
        }
    }
    int kth(LL x){
        int y=0;
        for(int i=20;i>=0;--i){
            if(y+(1<<i)<=n&&x>=a[y+(1<<i)]){
                y+=(1<<i);
                x-=a[y];
            }
        }
        return y+1;
    }
public:
    void solve(){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>s[i];
            add(i,i);
        }
        for(int i=n;i>=1;--i){
            p[i]=kth(s[i]);
            add(p[i],-p[i]);
        }
        for(int i=1;i<=n;++i){
            cout<<p[i]<<' ';
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