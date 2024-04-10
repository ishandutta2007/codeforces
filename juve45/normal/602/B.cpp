#include <bits/stdc++.h>

using namespace std;

int rmq[30][100009], RMQ[30][100009], lg[100009];
int ans;

int n;

void pre()
{
    lg[1]=0;
    for(int i=2;i<=100009;i++)
        lg[i]=lg[i/2]+1;
    
}

int minD(int start, int finish)
{
    int dist=finish-start+1;
    int h=lg[dist];
    return min(rmq[h][start], rmq[h][finish-(1<<h)+1]);
}

int maxD(int start, int finish)
{
    int dist=finish-start+1;
    int h=lg[dist];
    return max(RMQ[h][start], RMQ[h][finish-(1<<h)+1]);
}

int main()
{
    
    cin>>n;
    pre();
    for(int i=1;i<=n;i++)
    {
        cin>>rmq[0][i];
        RMQ[0][i]=rmq[0][i];
    }
    int i=1, pi=2;
    
    while(pi<=n)
    {
        for(int j=1;j+pi<=n+1;j++)
        {
            rmq[i][j]=min(rmq[i-1][j], rmq[i-1][j+pi/2]);
        }
        i++;
        pi*=2;
    }
    i=1;pi=2;
    
    while(pi<=n)
    {
        for(int j=1;j+pi<=n+1;j++)
        {
            RMQ[i][j]=max(RMQ[i-1][j], RMQ[i-1][j+pi/2]);
        }
        i++;
        pi*=2;
    }
    
    //cout<<maxD(1, 6)<<"asdasd\n";
    
    int start=1;
    int finish=2;
    
    while(start!=n)
    {        
        while(maxD(start, finish)-minD(start, finish)<=1 && finish!=n+1)
        {
            if(ans<finish-start+1)
                ans=finish-start+1;
            finish++;
        }
        start++;
    }
    cout<<ans<<'\n';
    return 0;
}