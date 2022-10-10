#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int s=0;
    while(t--){
        int n;
        s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            s+=x;
        }
        if((s/n)*n!=s)s=s/n+1;
        else s=s/n;
        cout<<s<<endl;
    }
}