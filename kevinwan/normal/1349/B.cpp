#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e6+10;
int a[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,k;
        scanf("%d%d",&n,&k);
        bool exi=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            if(x<k)a[i]=-1;
            else if(x==k)a[i]=0,exi=1;
            else a[i]=1;
        }
        if(!exi){printf("no\n");continue;}
        bool gud=0;
        for(int i=0;i<n-1;i++)if(a[i]>=0&&a[i+1]>=0)gud=1;
        for(int i=0;i<n-2;i++)if(a[i]>=0&&a[i+2]>=0)gud=1;
        if(n==1)gud=1;
        if(gud)printf("yes\n");
        else printf("no\n");
    }
}