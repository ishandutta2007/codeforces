#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,T;
vector<int> a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        int is0=-1,is1=-1,B=1;
        cin>>n>>m;
        for(i=1;i<=n;i++){
            int c1=-1,c2=-1,num=0;
            a[i].clear();b[i].clear();
            for(j=1;j<=m;j++){
                int x;
                scanf("%d",&x);
                a[i].push_back(x);
                b[i].push_back(x);
            }
            sort(b[i].begin(),b[i].end());
            for(j=1;j<=m;j++){
                if(a[i][j-1]!=b[i][j-1]){
                    ++num;
                    if(num<=2){
                        if(num==1)c1=j;
                        else c2=j;
                    }else B=0;
                }
            }
            if(is0<0)is0=c1,is1=c2;
            if((is0!=c1 || is1!=c2) && (c1>0 || a[i][is0-1]!=a[i][is1-1]))B=0;
            // cerr<<"i="<<i<<' '<<is0<<' '<<is1<<' '<<c1<<' '<<c2<<' '<<B<<endl;
        }
        if(is0>0){
            for(i=1;i<=n;i++)
                if(a[i][is0-1]<a[i][is1-1])B=0;
        }
        if(B){
            if(is0>0)cout<<is0<<' '<<is1<<endl;
            else cout<<1<<' '<<1<<endl;
        }else puts("-1");
    }
}