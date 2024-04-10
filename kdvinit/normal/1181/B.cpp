/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 1;
int a[N];
int n;

void print(vector<int> v)
{
    for(int i=0; i<v.size(); i++) cout<<v[i];
    cout<<endl;
}

vector<int> add(int l)
{
    vector<int> mx(n+3, 9);

    int n1 = l;
    int n2 = n-l;

    if(n1==0 || n2==0) return mx;

    vector<int> a1, a2, ans;
    for(int i=1; i<=n1; i++) a1.push_back(a[i]);
    for(int i=1; i<=n2; i++) a2.push_back(a[i+n1]);

    int i=n1-1, j=n2-1;
    int carry=0;
    while(1)
    {
        if(i<0 && j<0) break;

        int x, y;

        if(i<0) x=0;
        else x=a1[i--];

        if(j<0) y=0;
        else y=a2[j--];

        int z=x+y+carry;
        carry=z/10;
        z=z%10;

        ans.push_back(z);
    }
    if(carry!=0) ans.push_back(carry);

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> mn(vector<int>& v1, vector<int>& v2)
{
    int n1 = v1.size();
    int n2 = v2.size();

    if(n1!=n2)
    {
        if(n1<n2) return v1;
        else return v2;
    }

    for(int i=0; i<n1; i++)
    {
        if(v1[i]==v2[i]) continue;
        if(v1[i]<v2[i]) return v1;
        else return v2;
    }
    return v1;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';
    }

    int l1, l2;
    l1 = (n+1)/2;
    l2 = n/2;

    while(a[l2+1]==0) l2--;

    while(l1!=n && a[l1+1]==0) l1++;

    vector<int> v1 = add(l1);
    vector<int> v2 = add(l2);

    vector<int> ans = mn(v1, v2);

    print(ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}