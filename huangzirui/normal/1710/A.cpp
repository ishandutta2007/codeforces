#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(i=1;i<=k;i++)scanf("%d",&a[i]);
        bool B=0;long long Sum=0;
        if(m!=3){
            int Max=0;
            for(i=1;i<=k;i++)
                Sum+=a[i]/n==1?0:a[i]/n,Max=max(Max,a[i]/n);
            cerr<<Max<<endl;
            B|=(Sum>=m && (Max!=2 || m%2==0));Sum=0;
        }else{
            for(i=1;i<=k;i++)
                Sum+=a[i]/n>=3?3:0;
            B|=(Sum>=m);Sum=0;
        }
        if(n!=3){
            int Max=0;
            for(i=1;i<=k;i++)
                Sum+=a[i]/m==1?0:a[i]/m,Max=max(Max,a[i]/m);
            B|=(Sum>=n && (Max!=2 || n%2==0));Sum=0;
        }else{
            for(i=1;i<=k;i++)
                Sum+=a[i]/m>=3?3:0;
            B|=(Sum>=n);Sum=0;
        }
        if(B)puts("Yes");
        else puts("No");
    }
}