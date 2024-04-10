#include<bits/stdc++.h>
using namespace std;
long long hash1=1,hash2=1,mod1=1000000007,mod2=1000000009,stala1=13,stala2=17;
int conv(char a)
{
    return int(a)-48;
}
long long pref1[1000005];
long long suf1[1000005];
long long pref2[1000005];
long long suf2[1000005];
int licz[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int x=1;x<=b.size();x++)
    {
        pref1[x]=(pref1[x-1]+conv(b[x-1])*hash1)%mod1;
        hash1=(hash1*stala1)%mod1;
        pref2[x]=(pref2[x-1]+conv(b[x-1])*hash2)%mod2;
        hash2=(hash2*stala2)%mod2;
    }
    for(int x=b.size();x>0;x--)
    {
        suf1[x]=(suf1[x+1]*stala1+conv(b[x-1]))%mod1;
        suf2[x]=(suf2[x+1]*stala2+conv(b[x-1]))%mod2;
    }
    /*for(int x=1;x<=b.size();x++)
        cout<<pref1[x]<<" ";
    cout<<'\n';
    for(int x=1;x<=b.size();x++)
        cout<<suf1[x]<<" ";
    cout<<'\n';*/
    int maks;
    for(int x=b.size()-1;x>=0;x--)
    {
        if(pref1[x]==suf1[b.size()-x+1]&&pref2[x]==suf2[b.size()-x+1])
        {
            maks=x;
            break;
        }
    }
    for(int x=0;x<a.size();x++)
        licz[conv(a[x])]++;
    maks=b.size()-maks;
    for(int x=0;x<a.size();x++)
    {
        if(licz[conv(b[x%maks])]!=0)
        {
            cout<<conv(b[x%maks]);
            licz[conv(b[x%maks])]--;
        }
        else
        {
            cout<<(conv(b[x%maks])+1)%2;
            licz[(conv(b[x%maks])+1)%2];
        }
    }
	return 0;
}