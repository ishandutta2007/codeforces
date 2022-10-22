#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],pr[200009][2],suf[200009][2],lm[200009];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];lm[i]=-1;}
        deque<int>q;
        for(int i=0;i<n;i++)
        {

            while(!q.empty()&& a[i]<a[q.back()])
                q.pop_back();
            pr[i][0]=-1;
            if(!q.empty())pr[i][0]=q.back();
            q.push_back(i);
        }
        q.clear();
        for(int i=0;i<n;i++)
        {

            while(!q.empty()&& a[i]>a[q.back()])
                q.pop_back();
            pr[i][1]=-1;
            if(!q.empty())pr[i][1]=q.back();
            q.push_back(i);
        }
        q.clear();
        for(int i=n-1;i>0;i--)
        {

            while(!q.empty()&& a[i]<a[q.back()])
                q.pop_back();
            suf[i][0]=n;
            if(!q.empty())suf[i][0]=q.back();
            q.push_back(i);
        }

        q.clear();
        for(int i=n-1;i>0;i--)
        {

            while(!q.empty()&& a[i]>a[q.back()])
                q.pop_back();
            suf[i][1]=n;
            if(!q.empty())suf[i][1]=q.back();
            q.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            lm[suf[i][0]]=max(lm[suf[i][0]],pr[i][1]);
            lm[suf[i][1]]=max(lm[suf[i][1]],pr[i][0]);
        }
        ll ans=1;
        for(int i=1;i<n;i++)
        {
            lm[i]=max(lm[i],lm[i-1]);
            ans+=i-lm[i];

        }
        cout<<ans<<endl;

    }
return 0;
}