/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> conv(int x)
{
    vector<int> ans;
    int cnt=1, lst=x%2;
    x/=2;

    while(x!=0)
    {
        int y = x%2;
        if(y==lst) cnt++;
        else
        {
            lst=y;
            ans.push_back(cnt);
            cnt=1;
        }
        x/=2;
    }
    ans.push_back(cnt);

    return ans;
}

bool checkvec(vector<int>& a, vector<int>& b)
{
    int n = a.size();
    int m = b.size();

    if(n!=m) return false;

    if(a[0]>b[0] || a[n-1]>b[n-1]) return false;
    for(int i=1; i<n-1; i++) if(a[i]!=b[i]) return false;

    return true;
}

bool check(int x, int y)
{
    vector<int> a = conv(x);
    vector<int> b = conv(y);

    if(checkvec(a, b)) return true;

    reverse(a.begin(), a.end());
    return checkvec(a, b);
}

bool solve()
{
    int x, y;
    cin>>x>>y;

    if(x==y) return true;
    if(y%2==0) return false;

    if(x%2==0)
    {
        int x1 = 2*x+1;
        if(check(x1, y)) return true;

        while(x%2==0) x/=2;
        if(check(x, y)) return true;

        return false;
    }
    else return check(x, y);

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    if(solve()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}