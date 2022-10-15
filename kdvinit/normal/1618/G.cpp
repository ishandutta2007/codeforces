/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5e5+100;
int val;
int lft[N], rht[N], cnt2[N], pre_cnt[N], pre_sum[N];

int calc(int l, int r)
{
    int ln = pre_cnt[r] - pre_cnt[l-1];
    int ans = pre_sum[r] - pre_sum[r-ln];
    return ans;
}

void uni(int i)
{
    int l1 = lft[i], r1 = rht[i];
    int l2 = lft[i+1], r2 = rht[i+1];

    val-=calc(l1, r1);
    val-=calc(l2, r2);

    rht[l1]=r2;
    rht[r1]=r2;
    lft[l2]=l1;
    lft[r2]=l1;

    val+=calc(l1, r2);
}

void solve()
{
    int n, m, q;
    cin>>n>>m>>q;

    int a[n+1], b[m+1], c[n+m+1];
    map<int, int> cnt;

    val=0;
    for(int i=1; i<=n; i++) { cin>>a[i]; cnt[a[i]]++; val+=a[i]; }
    for(int i=1; i<=m; i++) cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    for(int i=1; i<=n; i++) c[i]=a[i];
    for(int i=1; i<=m; i++) c[n+i]=b[i];
    sort(c+1, c+n+m+1);

    int len = n+m;

    priority_queue<pair<int, int>> pq;

    for(int i=1; i<len; i++) pq.push({c[i]-c[i+1], i});

    pre_cnt[0]=0;
    pre_sum[0]=0;

    for(int i=1; i<=len; i++)
    {
        lft[i]=i;
        rht[i]=i;
        cnt2[i]=0;

        if(i==len) cnt2[i]=cnt[c[i]];
        if(i!=len && c[i]!=c[i+1]) cnt2[i]=cnt[c[i]];

        pre_cnt[i]=cnt2[i]+pre_cnt[i-1];
        pre_sum[i]=c[i]+pre_sum[i-1];
    }

    pair<int, int> qry[q+1];
    for(int i=1; i<=q; i++) { int x; cin>>x; qry[i]={x, i}; }
    sort(qry+1, qry+q+1);

    int res[q+1];
    for(int i=1; i<=q; i++)
    {
        int x = qry[i].first;
        int j = qry[i].second;

        while(!pq.empty())
        {
            pair<int, int> cur = pq.top();
            int dif = -cur.first;
            int ind = cur.second;
            if(dif>x) break;
            pq.pop();
            uni(ind);
        }

        res[j]=val;
    }

    for(int i=1; i<=q; i++) cout<<res[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}