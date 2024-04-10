#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        sum+=a&1;
    }
    cout<<min(sum,n-sum)<<endl;
    return 0;
}