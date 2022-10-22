#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int x,y,z,a,b,c;
    scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    bool suc=1;
    if(a<x)suc=0;
    a-=x;
    b+=a;
    if(b<y)suc=0;
    b-=y;
    c+=b;
    if(c<z)suc=0;
    if(suc)printf("YES");
    else printf("NO");
}