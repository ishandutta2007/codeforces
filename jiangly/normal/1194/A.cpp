#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    int T,x,n;
public:
    void solve(){
        cin>>T;
        while(T--){
            cin>>n>>x;
            cout<<x*2<<endl;
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