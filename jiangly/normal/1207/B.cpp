#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static const int MAX_N=50;
    int n,m;
    int a[MAX_N][MAX_N];
    int b[MAX_N][MAX_N]={};
    vector<pair<int,int>> sol;
public:
    Solver(){}
    void solve(){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
                if(i>0&&j>0&&a[i-1][j-1]==1&&a[i-1][j]==1&&a[i][j-1]==1&&a[i][j]==1){
                    b[i-1][j-1]=1;
                    b[i-1][j]=1;
                    b[i][j-1]=1;
                    b[i][j]=1;
                    sol.emplace_back(i,j);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(a[i][j]!=b[i][j]){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        cout<<sol.size()<<endl;
        for(auto [x,y]:sol){
            cout<<x<<' '<<y<<endl;
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