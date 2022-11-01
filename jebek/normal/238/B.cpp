#include <iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second

using namespace std;

typedef pair<long long,int> pii;
vector<pii>v;
long long n,h,ans1,ans2,ans3,a,ans[200000];

int main()
{
    cin>>n>>h;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(pii(a,i));
    }
    if(n==2)
    {
        cout<<0<<endl<<1<<" "<<1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    ans1=v.back().X+v[v.size()-2].X-v[1].X-v[0].X;
    ans2=v.back().X+max(v[v.size()-2].X,v[0].X+h)-v[1].X-min(v[0].X+h,v[2].X);
    ans3=v.back().X+max(v[v.size()-2].X,v[2].X+h)-v[0].X-min(v[1].X+h,v[2].X);
    cout<<min(ans1,min(ans2,ans3))<<endl;
    if(ans1<=ans2 && ans1<=ans3)
    {
        for(int i=0;i<n;i++)
            cout<<1<<" ";
        cout<<endl;
    }
    else if(ans2<=ans3)
    {
        ans[v[0].Y]=1;
        for(int i=0;i<n;i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
    }
    else
    {
        ans[v[0].Y]=1;ans[v[2].Y]=1;
        for(int i=0;i<n;i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;
    }
}