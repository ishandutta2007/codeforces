#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

map<int,int> ma;
int main(){
        for(int i=0;i<=1;i++){
                int n;
                cin>>n;
                while (n--){
                        int x,val;
                        cin>>x>>val;
                        ma[x]=max(ma[x],val);
                }
        }
        long long ans=0;
        for(auto i:ma) ans+=i.second;
        cout<<ans;
}