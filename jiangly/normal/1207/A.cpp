#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    int t;
    int b,p,f,h,c;
public:
    Solver(){}
    void solve(){
        cin>>t;
        while(t--){
            cin>>b>>p>>f>>h>>c;
            if(h<c){
                swap(p,f);
                swap(h,c);
            }
            int x=min(b/2,p);
            cout<<x*h+min(b/2-x,f)*c<<endl;
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