

    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int main(){
        int t;
        cin>>t;
        while(t--){
            ll x,y,k;
            cin>>x>>y>>k;
            ll tt=k*y+k-1;
            ll cnt=k;
            cnt+=tt/(x-1)+(tt%(x-1)!=0);
            cout<<cnt<<endl;
        }
    }