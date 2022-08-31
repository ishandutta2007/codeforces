#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    if(k1>k2){
        swap(k1,k2);
        swap(a1,a2);
    }
    cout<<max(0,n-a1*(k1-1)-a2*(k2-1))<<' ';
    if(n<=k1*a1){
        cout<<n/k1<<endl;
    }else{
        cout<<a1+(n-k1*a1)/k2<<endl;
    }
    return 0;
}