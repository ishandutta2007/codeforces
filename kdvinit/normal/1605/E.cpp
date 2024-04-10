/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1], dif[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) dif[i]=b[i]-a[i];

    int q; cin>>q;
    vector<array<int, 2>> xq;
    for(int i=1; i<=q; i++)
    {
        int x; cin>>x;
        xq.push_back({x, i});
    }
    sort(xq.begin(), xq.end());

    int mul[n+1]={0};
    mul[1]=1;

    dif[1]=-a[1];
    for(int i=1; i<=n; i++)
    {
        for(int j=2*i; j<=n; j+=i)
        {
            mul[j]-=mul[i];
            dif[j]-=dif[i];
        }
    }

    int tmp=0;
    for(int i=1; i<=n; i++) tmp+=abs(dif[i]);

//    cout<<"dif: ";
//    for(int i=1; i<=n; i++) cout<<dif[i]<<" ";
//    cout<<endl;
//    for(int i=1; i<=n; i++) cout<<mul[i]<<" ";
//    cout<<endl;

    int inc=0, dec=0;
    priority_queue<array<int, 2>> pq;

    for(int i=1; i<=n; i++)
    {
        if(mul[i]==0) continue;
        if((dif[i]*mul[i])>=0) inc++;
        else
        {
            dec++;
            dif[i]=abs(dif[i]);
            pq.push({-dif[i], i});
        }
    }

    int lst=0;
    int ans[q+1];

    //cout<<tmp<<endl;
    for(int i=0; i<q; i++)
    {
        int cur = xq[i][0];
        int ind = xq[i][1];
        int dfk = cur-lst;

        tmp += (inc*dfk);
        //cout<<tmp<<" "<<inc<<endl;
        while(!pq.empty())
        {
            auto x=pq.top();
            int j = x[1];
            //cout<<dif[j]<<" "<<cur<<endl;
            if(cur<=dif[j]) break;
            int prv = (dif[j]-lst);
            int now = (cur-dif[j]);
            tmp-=prv;
            tmp+=now;
            pq.pop();
            inc++;
            dec--;
        }
        //cout<<tmp<<" "<<dec<<endl;
        tmp -= (dec*dfk);
        //cout<<tmp<<endl;
        lst=cur;
        ans[ind] = tmp;
    }

    for(int i=1; i<=q; i++) cout<<ans[i]<<endl;
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}