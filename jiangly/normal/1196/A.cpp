// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int q;
ll a,b,c;
int main(){
    scanf("%d",&q);
    for(int _case=1;_case<=q;++_case){
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        printf("%I64d\n",(a+b+c)/2);
    }
    return 0;
}