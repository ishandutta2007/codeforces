#include <iostream>
#include <algorithm>
#define DMAX 100005
using namespace std;

string s;
int n, ans, r[DMAX], l[DMAX];

void max_right()
{
    for(int i=n;i>0;--i)
    {
        if(s[i-1]>='a' && 'z'>=s[i-1])
            r[i]=r[i+1]+1;
        else r[i]=r[i+1];
    }

}

void max_left()
{
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]>='A' && s[i-1]<='Z')
            l[i]=l[i-1]+1;
            else l[i]=l[i-1];
    }
}
/*
inline int lg(int k)
{
    int ans;
    while(k)
    {
        k=k/2;
        ans++;
    }
    return ans-1;
}

inline int p2(int k)
{
    return 1<<k;
}

void rmq()
{
    int lgn=lg(n);


    for(int i=2;i<=lgn;i++)
        for(int j=1;j<=n;j++)
        {
            r[i][j]=min(r[i-1][j], r[i-1][j+p2(j-1)]);
            //l[i][j]=min(l[i-1][j], l[i-1][j+p2(j-1)]);
        }
}
*/
void solve()
{
    for(int i=0;i<=n;i++)
    {
        int k=l[i]+r[i+1];
        if(k>ans)
            ans=k;
    }

    cout<<n-ans;
}

int main()
{
    cin>>s;
    n=s.size();

    max_right();

    max_left();

//    rmq();

    solve();

    return 0;
}