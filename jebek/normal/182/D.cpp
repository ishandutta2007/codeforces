#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string s1,s2;
long long p[200000],hs1,hs[200000],h[200000],h1,p1[200000];
int k,ans;
const long long MOD=1000000007,P=37,P1=101,MOD1=1000000009;

int main()
{
    cin>>s1>>s2;
    p1[0]=1;
    for(int i=1;i<=110000;i++)
        p1[i]=(p1[i-1]*P1)%MOD1;
    p[0]=1;
    for(int i=1;i<=110000;i++)
        p[i]=(p[i-1]*P)%MOD;
    if(s1.size()<s2.size())
        swap(s1,s2);
    int k=__gcd(s1.size(),s2.size());
    h[0]=hs[0]=int(s1[0]-'a')+1;
    for(int i=1;i<s1.size();i++)
        hs[i]=(hs[i-1]*P+int(s1[i]-'a')+1)%MOD,h[i]=(h[i-1]*P1+int(s1[i]-'a')+1)%MOD1;
    for(int i=0;i<s2.size();i++)
        hs1=(hs1*P+int(s2[i]-'a')+1)%MOD,h1=(h1*P1+int(s2[i]-'a')+1)%MOD1;
    if(hs1!=hs[s2.size()-1])
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=k;i++)
        if(k%i==0){
            bool mark=false;
            for(int j=i;j+i-1<s1.size() && !mark;j+=i)
                if((hs[j+i-1]-((hs[j-1]*p[i])%MOD)+MOD)%MOD!=hs[i-1] || (h[j+i-1]-((h[j-1]*p1[i])%MOD1)+MOD1)%MOD1!=h[i-1])
                    mark=true;
            if(!mark)
                ans++;
        }
    cout<<ans<<endl;
}