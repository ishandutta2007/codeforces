// Hydro submission #62fe364e3731a6f56a42c9c5@1661004829787
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> b;
        set<int> s;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]%10==5)b.push_back(a[i]+5);
            else if(a[i]%10==0)b.push_back(a[i]);
            else{
                int x=a[i];
                while(x%10!=6)x+=x%10;
                s.insert(x%20);
            }
        }
        if(b.size()){
            bool flag=b.size()==n;
            for(auto &x:b)if(x!=b[0])flag=false;
            cout<<(flag?"Yes":"No")<<endl;
        }
        else cout<<(s.size()==1?"Yes":"No")<<endl;
    }
    return 0;
}