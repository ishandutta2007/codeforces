#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
public:
    Solver(){}
    void solve(){
        int x=0;
        cout<<"?";
        for(int i=0;i<100;++i){
            cout<<' '<<(i+1<<7);
        }
        cout<<endl;
        int ans;
        cin>>ans;
        x|=(ans&127);
        cout<<"?";
        for(int i=0;i<100;++i){
            cout<<' '<<i;
        }
        cout<<endl;
        cin>>ans;
        x|=(ans>>7<<7);
        cout<<"! "<<x<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}