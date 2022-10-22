#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[21][2];
int a[200009];
#include<random>
#include <chrono>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,ans,nt;
int pos[200009];
vector<int>rr;
void ch(int x)

{
//cout<<x<<endl;
    for(int i=0;i<n;i++){
            int u=a[i]^x;
            if((u&ans)!=ans)continue;
            if((u&nt)!=0)continue;
            pos[a[i]^x]++;rr.push_back(a[i]^x);}
//cout<<x<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,x;
        cin>>l>>r;
        n=r-l+1;
        for(int i=0;i<20;i++)sum[i][0]=sum[i][1]=0;
        for(int i=l;i<=r;i++)
        {
            cin>>x;
            a[i-l]=x;
            for(int j=0;j<18;j++){if(x&(1<<j))sum[j][0]++;
            if(i&(1<<j))sum[j][1]++;
            }
        }
        ans=0,nt=0;
       for(int i=0;i<18;i++)
       {
        if(sum[i][0]!=sum[i][1])ans|=(1<<i);
       if(sum[i][0]!=r-l+1-sum[i][1])nt|=(1<<i);}
        rr.clear();
        ch(l);
        ch(r);
        for(int i=0;i<200;i++)
        {
            int h=rng()%(r-l+1);
            h+=l;
            ch(h);
        }
        int res=-1;
        for(int i=0;i<rr.size();i++)
        {
            if(pos[rr[i]]==202)res=rr[i];
            pos[rr[i]]=0;
        }

       cout<<res<<endl;

    }
    return 0;
}