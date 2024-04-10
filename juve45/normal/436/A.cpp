#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

priority_queue <pair<int, int> > p[2];
multiset <pair<int, int> > a[2][2];

int n, x;


void fill_it(int pp, int k, int cx)
{
 while(a[pp][k].begin()->x<=cx && !a[pp][k].empty())
    {
        pair<int,int> pii;
        pii.x=a[pp][k].begin()->y;
        pii.y=a[pp][k].begin()->x;
        p[k].push(pii);
        //cout<<"IN --> " << k << " --> " << pii.x <<' '<<pii.y<<'\n';
        a[pp][k].erase(a[pp][k].begin());
    }
}


int solve(int k)
{
    int ans=0, kk=k;
    int cx=x;
    while(!p[0].empty())p[0].pop();
    while(!p[1].empty())p[1].pop();

    fill_it(kk, k, x);
    fill_it(kk, 1-k, x);


    while(!p[k].empty())
    {
        pair<int, int> pi=p[k].top();
        p[k].pop();
        cx+=pi.x;
        ans++;
        fill_it(kk, 1-k, cx);
        //fill_it(kk, k, cx);
        k=1-k;

    }

    return ans;

}


int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>n>>x;
    int T,H,M;
    for(int i=1; i<=n; i++)
    {
        cin>>T>>H>>M;
        a[0][T].insert({H, M});
        a[1][T].insert({H, M});
        //p[T].push({H, M});
    }

    int ans1=solve(1);
    //cout<<"RESET\n";
    int ans2=solve(0);

    cout<<max(ans1, ans2)<<'\n';


    return 0;
}