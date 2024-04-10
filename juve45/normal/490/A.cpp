#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector <int> v1, v2, v3;
int a, n, t1, t2, t3;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        if(a==1) t1++, v1.pb(i);
        if(a==2) t2++, v2.pb(i);
        if(a==3) t3++, v3.pb(i);
    }

    if(t1>t2)
        t1=t2;
    if(t1>t3)
        t1=t3;
    cout<<t1<<'\n';
    for(int i=0;i<t1;i++)
        cout<<v1[i]<<' '<<v2[i]<<' '<<v3[i]<<'\n';
    return 0;
}