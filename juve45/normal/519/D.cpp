#include <bits/stdc++.h>

using namespace std;

map <pair<long long, long long>, long long> poz;
map <pair<long long, long long>, long long> neg;

long long a[30];
long long sum[100005];
char s[100005];

int main()
{
    //sfreopen("input.txt", "r", stdin);
    for(long long i=0;i<26;i++)
        cin>>a[i];

    cin>>s;
    long long lg=strlen(s);


    sum[0]=a[s[0]-'a'];
    for(long long i=1;i<lg;++i)
    {
        sum[i]+=sum[i-1]+a[s[i]-'a'];
    }

    long long ans=0;
    if(a[s[0]-'a']>=0)
    poz[{s[0]-'a',a[s[0]-'a']}]=1;

    if(a[s[0]-'a']<0)
    neg[{s[0]-'a',-a[s[0]-'a']}]=1;


    for(long long i=1;i<lg;i++)
    {
        if(sum[i-1]>=0)
            ans+=poz[{s[i]-'a',sum[i-1]}];
        else
            ans+=neg[{s[i]-'a',-sum[i-1]}];

        if(sum[i]>=0)
        poz[{s[i]-'a',sum[i]}]++;
        else
        neg[{s[i]-'a',-sum[i]}]++;
    }

    cout<<ans;

    return 0;
}