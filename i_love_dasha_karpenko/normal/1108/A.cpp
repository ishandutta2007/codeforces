#include <bits/stdc++.h>

using namespace std;
#define DIM 50
long long l1,r1,l2,r2,n;
int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    cin>>n;
    for (int i = 0;i<n;i++){
        cin>>l1>>r1>>l2>>r2;
        if (l1==l2 && l2==r2){cout<<l1+1<<' '<<l2;continue;}
        else cout<<l1<<' ';
        if (l1==l2)cout<<l2+1<<endl;
        else cout<<l2<<endl;
    }

}