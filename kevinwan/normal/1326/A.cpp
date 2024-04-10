#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        if(n==1)printf("-1\n");
        else{
            printf("2");
            for(int i=0;i<n-1;i++)printf("3");
            printf("\n");
        }
    }
}