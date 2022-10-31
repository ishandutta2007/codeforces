#include <bits\stdc++.h>

using namespace std;
    const int maxn=1e6;
    int sum[maxn];
int main()
{
    int k;
    long long ans=0;
    scanf("%d",&k);

    int in=0;

    string s;
    cin>>s;

    sum[0]=1;

    for (int i=0;i<s.size();i++)
    {
        in+=s[i]-'0';
        if (in>=k)
            ans+= sum[in-k];
        sum[in]++;
    }

    printf("%I64d",ans);
    return 0;
}