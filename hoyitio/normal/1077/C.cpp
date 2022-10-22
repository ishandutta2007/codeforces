#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e5+10;
int a[MAXN],b[MAXN];
int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    int ans[MAXN];
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i]==b[n-1])//
        {
            if((sum-a[i])%2==0&&(sum-a[i])/2==b[n-2])
            {
                //cout<<i+1<<" ";
                ans[cnt++] = i+1;
            }
        }
        else{
            if((sum-a[i])%2==0&&(sum-a[i])/2==b[n-1])
            {
                //cout<<i+1<<" ";
                ans[cnt++] = i+1;
            }
        }
    }
    cout<<cnt<<endl;
    for(int i = 0 ; i < cnt ; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}