#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if((b-a)%(c+d)==0) cout<<(b-a)/(c+d)<<endl;
        else cout<<-1<<endl;
    }
}