#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool bl[29];
int ds[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<29;i++)bl[i]=false;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){char x;cin>>x;bl[x-'a']=true;}
    ds[n-1]=INT_MIN;
    int ans=0;
    for(int i=n-2;i>=0;i--)
    {
        if(bl[s[i+1]-'a'])ds[i]=1;
        else ds[i]=ds[i+1]+1;
        ans=max(ans,ds[i]);
    }
    cout<<ans<<endl;

    }
    return 0;
}