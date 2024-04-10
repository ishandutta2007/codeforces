#include <iostream>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n,a[200000],q,k,k1,b[200000],x;
set<int>s;
map<int,long long>ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=1;
    }
    s.insert(0);
    s.insert(n);
    k=a[0];
    ans[a[0]]++;
    for(int i=1;i<n;i++)
    {
        k1=__gcd(k,a[i]);
        if(k1!=k)
            s.insert(i);
        k=k1;
        a[i]/=k;
        b[i]=k;
        ans[k]++;
    }
    for(int i=1;i<n;i++)
    {
        k=a[i];
        for(int j=i;j<n;j++)
        {
            k=__gcd(a[j],k);
       /*     if(k1!=k)
                s.insert(j);
            k=k1;*/
            a[j]/=k;
            b[j]*=k;
            if(b[j]!=b[j-1])
                s.insert(j);
            if(k!=1)
                ans[b[j]]++;
            if(k==1)
            {
              //  s.insert(j);
                set<int>::iterator it=s.end();
                --it;
                set<int>::iterator it1=it;
                --it;
                while(*it>=j)
                {
                    ans[b[*it]]+=(*it1)-(*it);
                    --it;
                    --it1;
                }
                ans[b[j]]+=(*it1)-j;
                break;
            }
        }
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x;
        cout<<ans[x]<<endl;
    }
}