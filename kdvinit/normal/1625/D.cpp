/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 3e5 + 100;
int a[N];
int n, k;

vector<int> mx2(vector<int>& ind1, vector<int>& ind2, int bm)
{
    vector<int> ans;
    int n1 = ind1.size();
    int n2 = ind2.size();
    
    if(n1==0 && n2==0)
    {
        return ans;
    }
    
    if(n1==0)
    {
        ans.push_back(ind2[0]);
        return ans;
    }
    
    if(n2==0)
    {
        ans.push_back(ind1[0]);
        return ans;
    }

    if(bm==-1)
    {
        if(ind1.size()) ans.push_back(ind1[0]);
        if(ind2.size()) ans.push_back(ind2[0]);
        return ans;
    }

    vector<int> a10, a11, a20, a21;
    int num = 1<<bm;

    for(int i: ind1)
    {
        int x = a[i];
        if((x&num)==0) a10.push_back(i);
        else a11.push_back(i);
    }

    for(int i: ind2)
    {
        int x = a[i];
        if((x&num)==0) a20.push_back(i);
        else a21.push_back(i);
    }

    if((k&num)==0)
    {
        if(a10.size() && a21.size())
        {
            ans.push_back(a10[0]);
            ans.push_back(a21[0]);
            return ans;
        }

        if(a11.size() && a20.size())
        {
            ans.push_back(a11[0]);
            ans.push_back(a20[0]);
            return ans;
        }

        vector<int> ans1 = mx2(a11, a21, bm-1);
        vector<int> ans2 = mx2(a10, a20, bm-1);

        if(ans1.size()>ans2.size()) return ans1;
        else return ans2;
    }
    else
    {
        vector<int> ans1 = mx2(a10, a21, bm-1);
        vector<int> ans2 = mx2(a11, a20, bm-1);

        if(ans1.size()>ans2.size()) return ans1;
        else return ans2;
    }
}

vector<int> mx1(vector<int>& ind, int bm)
{
    int nn = ind.size();
    if(nn<2) return ind;

    if(bm==-1) return ind;

    int num = 1<<bm;

    vector<int> a0, a1;
    for(int i: ind)
    {
        int x = a[i];
        if((x&num)==0) a0.push_back(i);
        else a1.push_back(i);
    }

    vector<int> ans, ans2;

    if((k&num)==0)
    {
        ans = mx1(a0, bm-1);
        ans2 = mx1(a1, bm-1);

        for(int x: ans2) ans.push_back(x);
        return ans;
    }
    else
    {
        ans = mx2(a0, a1, bm-1);
        return ans;
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> all;
    for(int i=1; i<=n; i++) all.push_back(i);

    vector<int> ans = mx1(all, 29);

    if(ans.size()<2) { cout<<-1<<endl; return; }

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}