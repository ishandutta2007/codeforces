#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int N=5e5;
    static constexpr int T=sqrt(N);
    int q;
    int a[N]={};
    int sum[T][T]={};
public:
    Solver(){}
    void solve(){
        cin>>q;
        while(q--){
            int op,x,y;
            cin>>op>>x>>y;
            if(op==1){
                --x;
                a[x]+=y;
                for(int i=1;i<T;++i){
                    sum[i][x%i]+=y;
                }
            }else{
                y=(y-1+x)%x;
                if(x<T){
                    cout<<sum[x][y]<<endl;
                }else{
                    int s=0;
                    for(int i=y;i<N;i+=x){
                        s+=a[i];
                    }
                    cout<<s<<endl;
                }
            }
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}