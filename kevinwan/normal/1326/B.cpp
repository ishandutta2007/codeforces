#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int main(){
    int n;
    scanf("%d",&n);
    int cum=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        printf("%d ",x+cum);
        if(x>0)cum+=x;
    }
}