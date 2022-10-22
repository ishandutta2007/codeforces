#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
int n;char a[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x=0,y=0;
        map<PII,int>mp;
        mp[PII(0,0)]=0;
        scanf("%d",&n);
        scanf("%s",a+1);
        int ans=INF;
        int l=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='L')x++;
            if(a[i]=='R')x--;
            if(a[i]=='U')y++;
            if(a[i]=='D')y--;
            if(mp.count(PII(x,y))){
                int k=mp[PII(x,y)];
                if(i-k<ans)ans=i-k,l=k+1;
            }
            mp[PII(x,y)]=i;
        }
        if(l==0)printf("-1\n");
        else printf("%d %d\n",l,l+ans-1);
    }
    return 0;
}
/*
*/