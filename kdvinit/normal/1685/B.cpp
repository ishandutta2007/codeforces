/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    string s;
    cin>>s;

    int n=s.size();

    int f[2]={0};
    for(char x: s) f[x-'A']++;

    if(f[0]!=(a+c+d)) return false;
    if(f[1]!=(b+c+d)) return false;

    int s2=0;
    int o1=0;
    int o2=0;

    vector<int> v1, v2;

    for(int i=0; i<n; i++)
    {
        char cur=s[i];
        int len=0;
        int j=i;

        while(j<n)
        {
            if(s[j]!=cur) break;

            len++;
            j++;

            if(cur=='A') cur='B';
            else cur='A';
        }
        
        int l2 = len/2;

        if(s[i]=='A')
        {
            if(len%2==1) s2+=l2;
            else { o1+=l2; v1.push_back(l2); }
        }
        else
        {
            if(len%2==1) s2+=(l2);
            else { o2+=(l2); v2.push_back(l2); }
        }

        i=j-1;
    }

    if(o2<d)
    {
        if(o2+s2<d)
        {
            int req = d - (o2+s2);
            if(req<=0) return true;

            sort(v1.begin(), v1.end());
            reverse(v1.begin(), v1.end());

            int trans=req;

            for(int x: v1)
            {
                if(req<=0) break;

                x--;
                if(x<=0) continue;

                req-=x;
                trans++;
            }

            o1-=trans;

            if(o1>=c && req<=0) return true;
            else return false;
        }
        else
        {
            o1+=(s2-(d-o2));
            if(o1>=c) return true;
            else return false;
        }
        
    }

    int req = c - (o1+s2);
    if(req<=0) return true;

    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());

    int trans=req;

    for(int x: v2)
    {
        if(req<=0) break;

        x--;
        if(x<=0) continue;

        req-=x;
        trans++;
    }

    o2-=trans;

    if(o2>=d && req<=0) return true;
    else return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}