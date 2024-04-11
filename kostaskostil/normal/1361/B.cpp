#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

istream& operator >> (istream& is, vector<int>& v)
{
    for (int& i:v)
        cin>>i;
    return is;
}

int mod = 1e9+7;
int bpow(int a, int b)
{
    int res=1;
    while (b>0)
    {
        if (b&1)
            res*=a, res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, p;
        cin>>n>>p;
        vector<int> k(n);
        cin>>k;
        if (p==1)
        {
            int s=0;
            for (int i:k)
                s++;
            cout<<s%2<<"\n";
            continue;
        }
        sort(k.begin(), k.end());
        reverse(k.begin(), k.end());
        vector<int> powers={1};
        while (powers.back()<=n)
            powers.push_back(powers.back()*p);
        int lt = 0;
        int pw = 1e9;
        int broken = -1;
        for (int i=0; i<n; i++)
        {

            int c=k[i];
            if (c<pw)
            {
                if (lt==0)
                    pw = c;
                else
                {
                    if (pw-c >= powers.size())
                    {
                        broken=i;
                        break;
                    }
                    lt*=powers[pw-c];
                    pw=c;
                    if (lt > n)
                    {
                        broken=i;
                        break;
                    }
                }
            }
            if (broken!=-1)
                break;
            if (lt > 0)
                lt--;
            else lt++;
        }
        lt = lt%mod;
        if (broken!=-1)
        {
            for (int i=broken; i<n; i++)
            {
                lt*=bpow(p, pw-k[i]);
                lt--;
                lt%=mod;
                lt+=mod;
                lt%=mod;
                pw=k[i];
            }
        }
        lt*=bpow(p, pw);
        lt%=mod;
        cout<<lt<<"\n";
    }
}