#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
ll ans,ans1,ans2,ans3,m,a,b,c,d;

void check()
{
    ans=ans1=-1;
    for(int i=1;i<m+10;i++)
    {
        a=(a*c+d)%m;
        if(a==b)
        {
            ans=i;
            break;
        }
    }
    for(int i=1;i<m+10;i++)
    {
        a=(a*c+d)%m;
        if(a==b)
        {
            ans1=i;
            break;
        }
    }
}

int main()
{
    cin>>m>>a>>b>>c>>d;
    check();
    ans2=ans;
    ans3=ans1;
    cin>>a>>b>>c>>d;
    check();
    if(ans==-1 || ans2==-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(ans1==-1 || ans3==-1)
    {
        if(ans3==-1)
            swap(ans3,ans1),swap(ans,ans2);
        if(ans3==-1)
        {
            if(ans==ans2)
            {
                cout<<ans<<endl;
                return 0;
            }
            cout<<-1<<endl;
            return 0;
        }
        if(ans>=ans2 && (ans-ans2)%ans3==0)
        {
            cout<<ans<<endl;
            return 0;
        }
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<m+10;i++)
        if(ans+ans1*i-ans2>=0 && (ans+ans1*i-ans2)%ans3==0)
        {
            cout<<ans+ans1*i<<endl;
            return 0;
        }
    for(int i=0;i<m+10;i++)
        if(ans2+ans3*i-ans>=0 && (ans2+ans3*i-ans)%ans1==0)
        {
            cout<<ans2+ans3*i<<endl;
            return 0;
        }
    cout<<-1<<endl;
}