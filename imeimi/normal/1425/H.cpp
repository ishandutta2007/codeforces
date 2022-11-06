#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 500011;
const ll mod = 998244353;
int K, M, t,A,B,C,D;
void solve(){
    cin>>A>>B>>C>>D;
    int po[4] = {0,0,0,0};
    int ab[2] = {B+C,A+D};//(0,1), (1,~)
    int bo[2] = {C+D,A+B};//(+1, -1)
    if(bo[1]%2==0){//+
        if(ab[0]){
            po[2]=1;
        }
        if(ab[1]){
            po[3]=1;
        }
    }
    else{
        if(ab[0]){
            po[1]=1;
        }
        if(ab[1]){
            po[0]=1;
        }
    }
    for(int i=0 ; i<4 ; i++){
        if(po[i]){
            cout<<"Ya ";
        }
        else{
            cout<<"Tidak ";
        }
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    for(int i=0 ; i<t ; i++)
        solve();
}