#include <bits/stdc++.h>
using namespace std;
string s[2001];
int v[2001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>s[i];
    for(i=0;i<n;i++)cin>>v[i];
    vector<int> ans;
    for(i=0;i<n;){
        if(v[i])i++;
        else{
            ans.push_back(i);
            for(j=0;j<n;j++)v[j]-=s[i][j]-'0';
            i=0;
        }
    }
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x+1);
}