#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool a[110];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 2 ; i < n ; i++)
    {
        if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
        {
            a[i+1] = 0;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}