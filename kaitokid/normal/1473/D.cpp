#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mxp[200009],mxs[200009];
int mnp[200009],mns[200009];
int pr[200009],suf[200009];
int main()
{
 ios::sync_with_stdio(0);
 cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
    string s;
    int n,m;
    cin>>n>>m>>s;
    mxs[n]=mns[n]=suf[n]=0;
    for(int i=0;i<n;i++)
    {
        pr[i]=pr[i-1];
        if(s[i]=='+')pr[i]++;else pr[i]--;
    mxp[i]=max(mxp[i-1],pr[i]);
    mnp[i]=min(mnp[i-1],pr[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
       mxs[i]=mxs[i+1];
       mns[i]=mns[i+1];
       if(s[i]=='+'){mxs[i]++,mns[i]++;}else {mns[i]--;mxs[i]--;}
       mxs[i]=max(mxs[i],0);
       mns[i]=min(mns[i],0);

    }
while(m--)
{
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    int mx=max(mxp[l-1],pr[l-1]+mxs[r+1]);

    int mn=min(mnp[l-1],pr[l-1]+mns[r+1]);
    cout<<mx-mn+1<<endl;
}
}
    return 0;
}