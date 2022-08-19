// luogu remote judge
#include<bits/stdc++.h>
template<class T>const T&min(const T&a,const T&b){
    if(a<b)
        return a;
    return b;
}
typedef long long ll;
ll a,b,c;
int main(){
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    if(a==b)
        printf("%I64d\n",a+b+c*2);
    else
        printf("%I64d\n",min(a,b)*2+1+c*2);
    return 0;
}