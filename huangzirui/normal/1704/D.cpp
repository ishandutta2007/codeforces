#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
int i,j,k,n,m;
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        ll s1=-1,s2=-1;
        int Id1=0,Id2=0,Ans=0;
        bool B=false;
        for(i=1;i<=n;i++){
            ll w=0;
            for(j=1;j<=m;j++){
                int x;scanf("%d",&x);
                w+=1ll*x*(m-j+1);
            }
            if(s1<0)s1=w,Id1=i;
            else if(w!=s1)s2=w,Id2=i;
            else B=true;
        }
        if(B){cout<<Id2<<' '<<s1-s2<<endl;}
        else cout<<Id1<<' '<<s2-s1<<endl;
    }
}
/*
0 0 1 0 1 0 0
0 0 1 1 2 2 2

0 1 0 0 0 1 0
0 1 1 1 1 2 2

0 1 0 0 0 0 1
0 1 1 1 1 1 2
*/