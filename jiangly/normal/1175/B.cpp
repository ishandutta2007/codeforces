// remote judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
const long long limit=1ll<<32;
int l;
string s;
long long x;
long long a[MAXN]={1};
int top;
int main(){
    scanf("%d",&l);
    for(;l>0;--l){
        cin>>s;
        if(s=="for"){
            int n;
            scanf("%d",&n);
            ++top;
            a[top]=min(a[top-1]*n,limit);
        }else if(s=="add"){
            x+=a[top];
            if(x>=limit){
                puts("OVERFLOW!!!");
                return 0;
            }
        }else
            --top;
    }
    printf("%I64d\n",x);
    return 0;
}