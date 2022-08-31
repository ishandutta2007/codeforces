#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    int T,a,b,n;
public:
    void solve(){
        cin>>T;
        while(T--){
            cin>>a>>b>>n;
            if(n%3==0){
                cout<<a<<endl;
            }else if(n%3==1){
                cout<<b<<endl;
            }else{
                cout<<(a^b)<<endl;
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