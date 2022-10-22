#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>fr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        fr.clear();
        int num=0,h=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            fr[x]++;
            if(fr[x]==1)num++;
            if(fr[x]==2){h++;num--;}
        }

        cout<<(num+1)/2+h<<endl;
    }
    return 0;
}