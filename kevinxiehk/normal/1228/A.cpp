#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        int t=i;
        bool b[10];
        bool idk=false;
        for(int j=0;j<=9;j++)b[j]=false;
        while(t>0){
            if(b[t%10]==true){idk=true;break;};
            b[t%10]=true;
            t-=(t%10);
            t/=10;
        }
        if(idk)continue;
        cout<<i<<endl;
        return 0;
    }
    cout<<"-1"<<endl;
    return 0;
}