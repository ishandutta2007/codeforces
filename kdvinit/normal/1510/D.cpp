#include<bits/stdc++.h>
#define int long long
using namespace std;
double f(double x)
{
    return log(x);
}
int32_t main()
{
ios::sync_with_stdio(0);
 cin.tie(0);
int t;
//cin>>t;
//while(t--)
    {int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    int digits[n];
    double logs[n];
    for(int i=0;i<n;i++)
        {logs[i]=f(a[i]);
        digits[i]=(a[i]%10);
        }
    double dp[n][10];//maxpro ending at digit j with first i
    int ok[n][10];//used or not
    int which[n][10];
    memset(ok,0,sizeof(ok));
    for(int i=0;i<n;i++)
        {for(int j=0;j<10;j++){dp[i][j]=-1;}
        }
    dp[0][digits[0]]=logs[0];
    ok[0][digits[0]]=1;
    for(int i=1;i<n;i++)
        {
            dp[i][digits[i]]=logs[i];ok[i][digits[i]]=1;which[i][digits[i]]=-1000;
            for(int j=0;j<10;j++)
                {
                    if(dp[i-1][j]>dp[i][j]){dp[i][j]=dp[i-1][j];ok[i][j]=0;}
                    for(int k=0;k<10;k++)
                        {int p=(digits[i]*k)%10;
                         if(p==j && dp[i-1][k]>=0)
                            {
                                if(dp[i-1][k]+logs[i]>dp[i][j]){dp[i][j]=dp[i-1][k]+logs[i];ok[i][j]=1;which[i][j]=k;}
                            }
                        }
                }
        }
   /* for(int i=0;i<n;i++)
        {for(int j=0;j<10;j++)
            {cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }*/
    if(dp[n-1][d]<0){cout<<"-1\n";exit(0);}
    vector<int> ans;
    int index=n-1;
    int value=d;
    while(index>=0)
        {if(ok[index][value]){ans.push_back(a[index]);value=which[index][value];if(value<0){break;}index--;}
        else{index--;}
        }
    cout<<ans.size()<<"\n";
    for(auto x:ans){cout<<x<<" ";}
    cout<<"\n";
    }
}