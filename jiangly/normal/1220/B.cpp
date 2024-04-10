#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL sqrtLL(LL x){
    LL c=0;
    for(LL i=1<<30;i>0;i>>=1){
        if((c+i)*(c+i)<=x){
            c+=i;
        }
    }
    return c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    vector<int> x(n);
    x[0]=sqrtLL((LL)a[0][2]*a[0][1]/a[1][2]);
    x[1]=sqrtLL((LL)a[0][1]*a[1][2]/a[0][2]);
    for(int i=0;i+2<n;++i){
        x[i+2]=sqrtLL((LL)a[i][i+2]*a[i+1][i+2]/a[i][i+1]);
    }
    for(int i=0;i<n;++i){
        cout<<x[i]<<' ';
    }
    cout<<endl;
    return 0;
}