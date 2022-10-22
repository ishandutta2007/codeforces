#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=5e3+10,mv=1e6+10;
int n,k;
int a[mn];
vector<int>d[mv];
int num[mv];
bool u[mv];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=1;i<mv;i++)d[i].reserve(5);
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
            int dif=abs(a[i]-a[j]);
            if(d[dif].size()>=5)continue;
            d[dif].push_back(j);
        }
    for(int i=1;i<mv;i++){
        int tot=0;
        for(int j=i;j<mv;j+=i){
            for(int x:d[j]){
                u[x]=num[a[x]%i]=0;
                if(++tot>10)break;
            }
            if(tot>10)break;
        }
        if(tot>10)continue;
        int ded=0;
        for(int j=i;j<mv;j+=i)for(int x:d[j]){
            if(u[x])continue;
            u[x]=1;
            if(++num[a[x]%i])ded++;
        }
        if(ded<=k){
            printf("%d",i);
            return 0;
        }
    }
}