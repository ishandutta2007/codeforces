#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    int T;
    int n,k;
public:
    void solve(){
        cin>>T;
        while(T--){
            cin>>n>>k;
            if(k%3!=0){
                if(n%3==0){
                    cout<<"Bob"<<endl;
                }else{
                    cout<<"Alice"<<endl;
                }
            }else{
                n%=(k+1);
                if(n==k){
                    cout<<"Alice"<<endl;
                }else if(n%3==0){
                    cout<<"Bob"<<endl;
                }else{
                    cout<<"Alice"<<endl;
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