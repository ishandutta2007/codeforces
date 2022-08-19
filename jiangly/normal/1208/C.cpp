#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int MAX_N=1e3+5;
    int n;
    int a[MAX_N][MAX_N];
public:
    void solve(){
        cin>>n;
        int cur=0;
        for(int i=0;i<n;i+=4){
            for(int j=0;j<n;j+=4){
                for(int x=i;x<i+4;++x){
                    for(int y=j;y<j+4;++y){
                        a[x][y]=cur++;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
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