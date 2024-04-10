#include <bits/stdc++.h>

using namespace std;
#define F for(int i=0;i<n;i++)
const int N=1e5;
long long n,m,k,ans1,ans2,maxa,maxb,mina=1e9,minb=1e9,zero,a[2][2*N];string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    F{cin>>a[0][i]>>a[1][i];maxa=max(maxa,a[0][i]);mina=min(mina,a[1][i]);}
    cin>>m;
    for(int i=0;i<m;i++){cin>>a[0][i]>>a[1][i];maxb=max(maxb,a[0][i]);minb=min(minb,a[1][i]);}
    ans1=maxb-mina;ans2=maxa-minb;
    cout<<max(zero,max(ans1,ans2));
    return 0;
}