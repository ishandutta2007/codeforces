#include<bits/stdc++.h>
using namespace std;
int X[1010];
int before[1010],after[1010];
void solve()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>X[i];
    memset(before,-1,sizeof(before));
    memset(after,-1,sizeof(after));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
            if(X[i]>X[j])
            {
                before[i]=j;
                break;
            }
        for(int j=i+1;j<N;j++)
            if(X[i]>X[j])
            {
                after[i]=j;
                break;
            }
    }
    for(int i=0;i<N;i++)
        if(before[i]!=-1&&after[i]!=-1)
        {
            puts("YES");
            cout<<before[i]+1<<" "<<i+1<<" "<<after[i]+1<<endl;
            return ;
        }
    puts("NO");
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}