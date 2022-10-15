#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, freq=0;
        cin>>n>>k;
        int dis[n];
        for(int i=0;i<n;i++)
        {
            int x, j;
            cin>>x;
            for(j=0;j<freq;j++)
            {
                if(dis[j]==x) break;
            }
            if(j==freq)
            {
                dis[j]=x;
                freq++;
            }
        }
        if(freq>k) { cout<<-1<<endl; continue; }
        cout<<k*n<<endl;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<k;i++)
            {
                if(i>=freq) cout<<dis[0]<<" ";
                else cout<<dis[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}