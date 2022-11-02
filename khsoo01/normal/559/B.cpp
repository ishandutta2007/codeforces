#include<bits/stdc++.h>
#define ll int
char a[200005],b[200005];
ll len;
bool solve(ll as, ll ae,ll bs,ll be) {
    if((ae-as)%2==0) {
        ll i;
        for(i=0;i<=ae-as;i++) {
            if(a[as+i]!=b[bs+i]){
                return false;
            }
        }
        return true;
    }
    else {
        ll apiv=(as+ae)/2,bpiv=(bs+be)/2;
        if(solve(as,apiv,bs,bpiv) && solve(apiv+1,ae,bpiv+1,be))return true;
        if(solve(as,apiv,bpiv+1,be) && solve(apiv+1,ae,bs,bpiv))return true;
        return false;
    }
}
int main()
{
    scanf("%s%s",&a,&b);
    len=strlen(a);
    printf("%s",solve(0,len-1,0,len-1)?"YES":"NO");
}