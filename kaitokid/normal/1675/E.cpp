#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool bl[50];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        string s;
        cin>>n>>k>>s;
        for(int i=0;i<30;i++)bl[i]=false;
        for(int i=0;i<n;i++)
        {
            int u=s[i]-'a';
            while(u>0 && k>0 )
            {
                if(bl[u]){u--;continue;}
                bl[u]=true;
                k--;
                u--;
            }
            while(bl[u])u--;
            s[i]=char('a'+u);
        }
        cout<<s<<endl;

    }

    return 0;

}