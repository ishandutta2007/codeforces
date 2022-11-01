#include <bits\stdc++.h>

using namespace std;
#define mp make_pair
#define f first
#define pb push_back
#define ll long long
#define s second
#include <bits\stdc++.h>
// PROD SUM DIF MIN MAX PRINT SCAN
using namespace std;

typedef vector<int> BigInt;

void print(BigInt x)
{
    if (!x.size())
        cout<<'0'; else
    for (int i=0;i<x.size();i++)
    {
        cout<<x[i];
    }
    cout<<endl;
}


BigInt scan(string s)
{
    BigInt ans;
    ans.resize(s.size());

    for (int i=ans.size()-1;i>=0;i--)
    {
        ans[i]=(int)s[i]-48;
    }
    return ans;
}


BigInt mn(BigInt a,BigInt b)
{
    if (a.size()<b.size())
    return a;

    if (a.size()>b.size())
    return b;

    for (int i=0;i<a.size();i++)
    {
        if (a[i]<b[i])
            return a;

        if (a[i]>b[i])
            return b;
    }

    return a;
}


BigInt mx(BigInt a,BigInt b)
{
    if (a.size()>b.size())
    return a;

    if (a.size()<b.size())
    return b;

    for (int i=0;i<a.size();i++)
    {
        if (a[i]>b[i])
            return a;

        if (a[i]<b[i])
            return b;
    }

    return a;
}


BigInt sum(BigInt a, BigInt b)
{
    BigInt ans;

    ans.resize(max(a.size(),b.size())+1);

    for (int i=0;i<ans.size();i++)
        ans[i]=0;

    int i=ans.size()-1;

    while (a.size()!=b.size())
    {
        if (a.size()<b.size())
            a.insert(a.begin(),0);
        else
            b.insert(b.begin(),0);
    }
    while (a.size()>0&&b.size()>0)

    {

        int r=a.back()+b.back();
        ans[i]+=r;
        if(ans[i]>9)
        {
            ans[i]-=10;
            ans[i-1]++;
        }

        a.pop_back(); b.pop_back();
        i--;
    }

  while (ans[0]==0&&ans.size())
        ans.erase(ans.begin());

    return ans;
}

BigInt fiscan(int x) // Scan from int
{
    BigInt ans;
    while (x)
    {
        ans.push_back(x%10);
        x/=10;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

BigInt dif(BigInt a,BigInt b) // A GUARANTED > B
{
    BigInt ans;

    ans.resize(max(a.size(),b.size())+1);


    for (int i=0;i<ans.size();i++)
        ans[i]=0;

    int i=ans.size()-1;

    while (a.size()!=b.size())
    {
        if (a.size()<b.size())
            a.insert(a.begin(),0);
        else
            b.insert(b.begin(),0);
    }

    while (a.size()>0&&b.size()>0)
    {
        int r=a.back()-b.back();
        ans[i]+=r;
        if(ans[i]<0)
        {
            ans[i]+=10;
            ans[i-1]--;
        }

        a.pop_back(); b.pop_back();
        i--;
    }
       while (ans[0]==0&&ans.size())
        ans.erase(ans.begin());

    return ans;
}


BigInt prod(BigInt a,BigInt b)
{
    BigInt ans,asav=a;


    for (int i=b.size()-1;i>=0;i--)
    {
        a=asav;  a.insert(a.begin(),0); // E.g a=223 -> 0223 *5->  15
          for (int j=0;j<a.size();j++)
            a[j]=0;

        for (int j=a.size()-1;j>=1;j--)
        {
            a[j]+=asav[j-1]*b[i];

            while (a[j]>9)
            {
                a[j]-=10;
                a[j-1]++;
            }
        }

        for (int j=0;j<b.size()-1-i;j++)
            a.push_back(0);

        ans=sum(ans,a);
    }
    return ans;
}


const int eps=1e-8,maxn=1e5;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a;
    for (int i=0;i<n;i++){
        int x;

        scanf("%d",&x);
        a.pb(x);
    }

    while (a[0] == 0){
        a.erase(a.begin());
        if (a.empty())
        {
            cout<<0;
            exit(0);
        }
    }

    while (a.back()==0){
        a.pop_back();
        if (a.empty())
        {
            cout<<0;
            exit(0);
        }
    }

    int last = 0;
    BigInt c = fiscan(1);
    for (int i=1;i<a.size();i++){
        if (a[i] == 1){
            c=prod(c,fiscan(i-last));
            last = i;
        }
    }

    print(c);
    return 0;
}