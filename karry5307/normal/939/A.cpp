#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num[100001];
inline ll get(ll cnt)
{
    return num[num[num[cnt]]];
}
int main()
{
    cin>>cnt;
    for(register int i=1;i<=cnt;i++)
    {
        cin>>num[i];
    }
    for(register int i=1;i<=cnt;i++)
    {
        if(i==get(i))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}