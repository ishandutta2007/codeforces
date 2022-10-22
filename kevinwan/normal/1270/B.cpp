#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
int p[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",p+i);
        bool done=0;
        for(int i=0;i<n-1;i++){
            if(abs(p[i+1]-p[i])>=2){
                printf("YES\n%d %d\n",i+1,i+2);
                done=1;
                break;
            }
        }
        if(!done)printf("NO\n");
    }
}