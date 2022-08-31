// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(;T--;){
        int n,s,t;
        scanf("%d%d%d",&n,&s,&t);
        printf("%d\n",n-min(s,t)+1);
    }
    return 0;
}