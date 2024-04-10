#include <bits/stdc++.h>

using namespace std;




int t,n,m,a[113],b[113];

map<int,int> arr[113][113];
int go(int ind,int j,int cnt)
{
    if(ind == n && j == m)return max(0,cnt);
    if(arr[ind][j].find(cnt)!= arr[ind][j].end()) return arr[ind][j][cnt];
    int ans = cnt;

    if(ind<n)
    ans = max(ans,go(ind+1,j,cnt + a[ind]));
    if(j<m)
    ans = max(ans,go(ind,j+1,cnt + b[j]));

    return arr[ind][j][cnt]=ans;
}

int main()
{
    ios::sync_with_stdio(0);

    cin>>t;
    while(t--)
    {

        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>m;
        for(int i=0;i<m;i++)cin>>b[i];

        for(int i=0;i<=n+5;i++)
            for(int j=0;j<=m+5;j++)
                arr[i][j].clear();

        cout<<go(0,0,0)<<"\n";
    }

    return 0;

}