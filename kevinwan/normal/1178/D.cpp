#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e4+10;
const ll mod=998244353;
bool p[mn];
pii num[mn];
int main()
{
    int n,i,j;
    memset(p,1,sizeof(p));
    p[0]=p[1]=0;
    for(i=2;i*i<mn;i++)if(p[i])for(j=i*i;j<mn;j+=i)p[j]=0;
    scanf("%d",&n);
    for(i=0;n+i<mn;i++){
        if(p[n+i]&&p[2+i]){
            for(j=1;j<=n;j++)num[j].first=2,num[j].second=j;
            num[n].first+=i;
            num[n-1].first+=i;
            sort(num+1,num+1+n);
            printf("%d\n",n+i);
            while(num[n].first){
                for(j=1;j<=num[n].first;j++){
                    printf("%d %d\n",num[n].second,num[n-j].second);
                    num[n-j].first--;
                }
                num[n].first=0;
                sort(num+1,num+1+n);
            }
            return 0;
        }
    }
    for(i=0;n+2*i<mn;i++){
        if(p[n+2*i]&&p[2+i]){
            for(j=1;j<=n;j++)num[j].first=2,num[j].second=j;
            num[n].first+=i;
            num[n-1].first+=i;
            num[n-2].first+=i;
            num[n-3].first+=i;
            sort(num+1,num+1+n);
            printf("%d\n",n+2*i);
            while(num[n].first){
                for(j=1;j<=num[n].first;j++){
                    printf("%d %d\n",num[n].second,num[n-j].second);
                    num[n-j].first--;
                }
                num[n].first=0;
                sort(num+1,num+1+n);
            }
            return 0;
        }
    }
}