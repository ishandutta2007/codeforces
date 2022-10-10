#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,s1,s2;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        s1=0;s2=0;
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x>s1)s2=s1,s1=x;
            else if(x>s2)s2=x;
        }
        cout<<s1+s2<<endl;
    }
}