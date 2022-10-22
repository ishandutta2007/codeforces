#include <bits/stdc++.h>

using namespace std;
long long niz[4000000];
bool cmp(long long a, long long b){
    if(a>b)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,i;
    unsigned long long konst=0,z=0,k;
    cin>>n;
    while(pow(4,konst)<n)konst++;
    konst++;
    k=konst;
    for(i=1;i<=n;i++)cin>>niz[i];
    sort(niz+1,niz+1+n,cmp);
    for(i=1;i<=n;i++){
        z+=niz[i]*k;
        if(i==pow(4,konst-k))k--;
    }
    cout<<z;
    return 0;
}