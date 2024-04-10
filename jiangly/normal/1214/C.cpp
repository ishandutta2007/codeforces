#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin>>n>>s;
    vector<int> sum(n+1);
    int mn=0;
    for(int i=0;i<n;++i){
        sum[i+1]=sum[i]+(s[i]=='('?1:-1);
        mn=min(mn,sum[i+1]);
    }
    if(sum[n]==0&&mn>=-1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}