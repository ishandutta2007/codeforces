#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(n>m){puts("No");}
        else{
            if(n%2==0){
                if(m%2)puts("No");
                else{
                    cout<<"Yes"<<endl;
                    for(i=1;i<=n-2;i++)printf("1 ");
                    cout<<(m-(n-2))/2<<' '<<(m-(n-2))/2<<endl;
                }
            }else{
                cout<<"Yes"<<endl;
                for(i=1;i<=n-1;i++)printf("1 ");
                cout<<(m-(n-1))<<endl;
            }
        }
    }
}