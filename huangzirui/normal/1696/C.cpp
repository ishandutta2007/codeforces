#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
int i,j,k,n,m,a[maxn],b[maxn];
int S[maxn],Num[maxn];
// string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        cin>>m;
        for(i=1;i<=m;i++){
            scanf("%d",&b[i]);
            int s=b[i],num=1;
            while(s%k==0)s/=k,num*=k;
            S[i]=s;Num[i]=num;
        }
        int p1=1,p2=1;
        bool B=true;
        for(;p1<=n;p1++){
            int s=a[p1],num=1;
            while(s%k==0)s/=k,num*=k;
            while(p2<=m){
                // cerr<<"p1="<<p1<<' '<<p2<<' '<<s<<' '<<num<<' '<<Num[p2]<<' '<<S[p2]<<endl;
                if(s!=S[p2]){B=false;break;}
                int tmp=min(num,Num[p2]);
                num-=tmp;Num[p2]-=tmp;
                // cerr<<"tmp="<<tmp<<' '<<num<<' '<<Num[p2]<<' '<<B<<endl;
                if(!Num[p2])++p2;
                if(!num)break;
            }
            // cerr<<"num="<<num<<endl;
            if(num)B=false;
        }
        if(p2<=m)B=false;
        if(B)puts("Yes");
        else puts("No");
    }
}