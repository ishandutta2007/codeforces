#include<bits/stdc++.h>
#define LL long long
#define PB push_back
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        int a=0,b=0;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            if(x&1)a=1;
            else b=1;
        }
        if(a==0||(b==0&&n%2==0))printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
/*
*/