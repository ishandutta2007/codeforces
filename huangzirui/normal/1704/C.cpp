#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn],w[maxn],cnt;
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=m;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+m);
        cnt=0;
        for(i=1;i<m;i++)w[++cnt]=a[i+1]-a[i]-1;
        w[++cnt]=a[1]-a[m]+n-1;
        sort(w+1,w+1+cnt);
        reverse(w+1,w+1+cnt);
        int Ans=0;
        for(i=1;i<=cnt;i++){
            int nt=(i-1)*2,s=w[i]-2*nt;
            // cerr<<"i="<<i<<' '<<w[i]<<endl;
            if(s<=0)break;
            if(s<=2){Ans++;break;}
            Ans+=s-1;
        }
        printf("%d\n",n-Ans);
    }
}