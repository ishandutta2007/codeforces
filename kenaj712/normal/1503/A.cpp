#include<bits/stdc++.h>
using namespace std;
int licz[2];
int pom_licz[2];
bool check(string a)
{
    int sum = 0;
    for(auto x:a)
    {
        if(x == '(')
            sum++;
        else
            sum--;
        if(sum < 0)
            return false;
    }
    return true;
}
void solve()
{
    licz[0] = 0;
    licz[1] = 0;
    pom_licz[0] = 0;
    pom_licz[1] = 0;
    int a;
    string d;
    cin>>a>>d;
    for(auto x:d)
        licz[x - '0']++;
    if(licz[0]%2)
    {
        cout<<"NO\n";
        return;
    }
    for(int x=0;x<2;x++)
        pom_licz[x] = licz[x];
    string res1 = "" , res2 = "";
    for(auto x:d)
    {
        if(x == '1')
        {
            if(pom_licz[1] > licz[1]/2)
            {
                res1 += '(';
                pom_licz[1]--;
            }
            else
            {
                res1 += ')';
            }
        }
        else
        {
            if(pom_licz[0]%2)
                res1 += '(';
            else
                res1 += ')';
            pom_licz[0]--;
        }
    }
    for(int x=0;x<a;x++)
    {
        if(d[x] == '1')
            res2 += res1[x];
        else
        {
            if(res1[x] == ')')
                res2 += '(';
            else
                res2 += ')';
        }
    }
   // cout<<res1<<" "<<res2<<'\n';
    if(check(res1) && check(res2))
    {
        cout<<"YES\n"<<res1<<" "<<res2<<'\n';
    }
    else
        cout<<"NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}