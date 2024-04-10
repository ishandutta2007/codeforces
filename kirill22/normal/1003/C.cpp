#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b , x;
    cin >> a >> b;
    cout << fixed << setprecision(10);
    long double ans=0.0000000000000;
    long double m[a];
    long double sum[a+1];
    sum[0]=0;
    for (int i=0;i<a;++i){
        cin >> x;
        sum[i+1]=sum[i]+x;
        m[i]=x;
    }
    for (int i=0;i<=a-b;++i){
        for(int j=i+b-1;j<a;++j){
            if ((sum[j+1]-sum[i])/(j-i+1)>ans){
                    ans=(sum[j+1]-sum[i])/(j-i+1);
        }
    }
    }
    cout << ans;


}