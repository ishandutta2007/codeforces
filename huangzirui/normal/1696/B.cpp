#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        k=0;
        cin>>n;
        int chs=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(chs==i-1 && a[i]==0)++chs;
        }
        for(i=chs;i<n;i++)
            if(a[i]==0 && a[i+1]!=0)++k;
        cout<<min(2,k)<<endl;
    }
}