#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int freq[102]={0},odd=0,even=0,poss=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            freq[x]++;
            if(x%2==0) even++;
            else odd++;
            if(freq[x-1]!=0 || freq[x+1]!=0) poss++;
        }
        if(even%2==1 && poss==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}