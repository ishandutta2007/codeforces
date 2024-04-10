#include <iostream>

using namespace std;

bool mark;
char c1[200],c2[200];
int n,a[20],ans=20,sum;
char s[10]={'R','G','B','Y','W','1','2','3','4','5'};

int f(char c)
{
    for(int i=0;i<10;i++)
        if(s[i]==c)
            return i;
}

bool check(int i,int j)
{
    if(c1[i]==c1[j] && c2[i]==c2[j])
        return false;
    if(c1[i]!=c1[j] && (a[f(c1[i])] || a[f(c1[j])]))
        return false;
    if(c2[i]!=c2[j] && (a[f(c2[i])] || a[f(c2[j])]))
        return false;
    return true;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>c1[i]>>c2[i];
    for(int i=0;i<1024;i++)
    {
        for(int j=0;j<10;j++)
            a[j]=(((1<<j)&i)>>j);
        mark=false;
        for(int j=0;j<n-1 & !mark;j++)
            for(int k=j+1;k<n & !mark;k++)
            {
                if(check(j,k))
                    mark=true;
            }
        if(mark==false)
        {
            sum=0;
            for(int j=0;j<10;j++)
                sum+=a[j];
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
}