#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m[100009];
int h;
vector<int>u;
bool ans;
void go(int x,int p,int sum)
{
    if(x==h){if((sum==0) && (p>1))ans=true;
    return;}
    go(x+1,p,sum);
    go(x+1,p+1,sum+u[x]);
    go(x+1,p+1,sum-u[x]);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<100009;i++)m[i]=0;
        u.clear();
        int l=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            x=abs(x);
            if(x==0)continue;
        if(m[x]==0){u.push_back(x);m[x]++;l++;}
        }
         h=u.size();
        if(l<n){cout<<"YES\n";continue;}
       ans=false;
       go(0,0,0);

       if(ans)cout<<"YES\n";
       else cout<<"NO\n";
         }
    return 0;
}