#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void go(vector<int>v)
{
    if(v.size()==3)
    {
        cout<<"? "<<2<<" "<<v[0]<<" "<<v[1]<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s=="YES")
        {
        cout<<"? "<<2<<" "<<v[0]<<" "<<v[1]<<endl;
        fflush(stdout);
        cin>>s;

        }
        if(s=="YES")
        {
            vector<int>gg;
            gg.push_back(v[0]);
            gg.push_back(v[1]);
            go(gg);
            return;
        }
        if(s=="NO")
        {
        cout<<"? "<<1<<" "<<v[0]<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="YES")
        {
            vector<int>gg;
            gg.push_back(v[0]);
            gg.push_back(v[2]);
            go(gg);
            return;
        }
            vector<int>gg;
            gg.push_back(v[1]);
            gg.push_back(v[2]);
            go(gg);
            return;

        }
    }

    if(v.size()<3)
    {
        cout<<"! "<<v[0]<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s[1]==')')return;
        cout<<"! "<<v[1]<<endl;
        fflush(stdout);
        cin>>s;
        return;

    }
    int g=v.size();
    g/=4;
    vector<int>a,b,c,d;
    for(int i=0;i<g;i++)a.push_back(v[i]);
    for(int i=g;i<2*g;i++)b.push_back(v[i]);
    for(int i=2*g;i<3*g;i++)c.push_back(v[i]);
    for(int i=3*g;i<4*g;i++)d.push_back(v[i]);
    for(int i=0;i+4*g<v.size();i++)
    {
        if(i==0)a.push_back(v[i+4*g]);
        if(i==1)b.push_back(v[i+4*g]);
        if(i==2)c.push_back(v[i+4*g]);
        if(i==3)d.push_back(v[i+4*g]);

    }
    cout<<"? "<<a.size()+b.size()<<" ";
    for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
    for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
    cout<<endl;
    fflush(stdout);
    string s;
    cin>>s;
    if(s=="NO")
    {
        swap(a,c);
        swap(b,d);
    }
    cout<<"? "<<c.size()<<" ";
    for(int i=0;i<c.size();i++)cout<<c[i]<<" ";
    cout<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="NO")
    {
        swap(c,d);
    }
    vector<int>gg;
    for(int i=0;i<a.size();i++)gg.push_back(a[i]);
    for(int i=0;i<b.size();i++)gg.push_back(b[i]);
    for(int i=0;i<c.size();i++)gg.push_back(c[i]);
    go(gg);

    }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*int n=100000,ans=0;
    while(n>3)
    {
        n-=(n/4);
        ans+=2;
    }
    cout<<ans<<endl;
*/
    int n;
    cin>>n;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);

    }
    go(v);
    return 0;
}