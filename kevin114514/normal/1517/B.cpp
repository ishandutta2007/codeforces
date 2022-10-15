#include<bits/stdc++.h>
using namespace std;
int t[110][110];
int ans[110][110];
pair<int,pair<int,int> > P[11000];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j]=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>t[i][j];
                P[i*m+j]=make_pair(t[i][j],make_pair(i,j));
            }
        sort(P,P+n*m);
        for(int i=0;i<m;i++)
        {
            ans[P[i].second.first][i]=P[i].first;
            t[P[i].second.first][P[i].second.second]=-1;
            //cout<<i<<" "<<P[i].second.first<<" "<<P[i].second.second<<endl;
        }
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
                if(ans[i][j]==-1)
                {
                	//cout<<"!"<<i<<" "<<j<<endl;
                    while(t[i][cnt]==-1)
                    {
                    	//cout<<i<<" "<<j<<" "<<cnt<<endl;
                        cnt++;
                    }
                    ans[i][j]=t[i][cnt];
                    t[i][cnt]=-1;
                }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<ans[i][j]<<" ";
            puts("");
        }
    }
    return 0;
}