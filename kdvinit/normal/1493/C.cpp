/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i] = x - 'a' + 1;
    }

    if(n%k != 0) { cout<<-1<<endl; return; }

    int freq[27]={0};
    for(int i=1; i<=n; i++)
    {
        freq[a[i]]++;
    }

    int lst=n+2;
    int lsti=0;
    while(1)
    {
        lst--;
        if(lst!=n+1) { freq[a[lst]]--; lsti=a[lst]; }

        int xtra = n-lst+1;
        int need = 0;

        for(int i=1; i<=26; i++)
        {
            int x = freq[i];
            x%=k;
            if(x!=0) need += (k-x);
        }

        if(need<=xtra)
        {
            if(lst==n+1)
            {
                for(int i=1; i<lst; i++)
                {
                    char x = a[i] + 'a' - 1;
                    cout<<x;
                }
                cout<<endl;
                return;
            }

            int ind=0;
            for(int i=lsti+1; i<=26; i++)
            {
                int n1 = freq[i]%k;
                if(n1!=0) n1 = k-n1;

                int n2 = (freq[i]+1)%k;
                if(n2!=0) n2 = k-n2;

                int tmp_need = need - n1 + n2 + 1;
                if(tmp_need<=xtra)
                {
                    need = tmp_need;
                    ind=i;
                    break;
                }
            }

            if(ind==0) continue;

            char x;
            for(int i=1; i<lst; i++)
            {
                x = a[i] + 'a' - 1;
                cout<<x;
            }

            x = ind + 'a' - 1;
            cout<<x;
            freq[ind]++;

            int over = xtra - need;
            while(over--)
            {
                cout<<'a';
            }

            for(int i=1; i<=26; i++)
            {
                int y = freq[i]%k;
                if(y!=0) y = k - y;
                while(y--)
                {
                    x = i + 'a' - 1;
                    cout<<x;
                }
            }
            cout<<endl;

            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}