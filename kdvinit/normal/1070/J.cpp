#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
    {int n,m,k;
     cin>>n>>m>>k;
     string s;
     int a[26];
     cin>>s;
     memset(a,0,sizeof(a));
     for(auto x:s)
        {a[x-'A']++;
        }
    int nice[27][k+5];
    memset(nice,0,sizeof(nice));
     nice[0][0]=1;
     for(int i=1;i<27;i++)
        {for(int j=0;j<k+5;j++)
            {nice[i][j]=nice[i-1][j];
            if(j>=a[i-1]){nice[i][j]|=nice[i-1][j-a[i-1]];}
            }
        }
    int poss=0;
    for(int i=0;i<k+5;i++)
        {if(nice[26][i] && (i>=n && k-i>=m)){poss=1;break;}
        //if(nice[i]){cout<<i<<"\n";}
        }
    if(poss){cout<<"0\n";continue;}
    int maxa=1e16;
    //cout<<"YES\n";
    for(int i=0;i<26;i++)
        {if(a[i]==0){continue;}
            vector<int> b;
         for(int j=0;j<26;j++)
            {if(j==i || a[j]==0){continue;}
             b.push_back(a[j]);
            }
        memset(nice,0,sizeof(nice));
        nice[0][0]=1;
        int z=b.size();
        for(int ai=1;ai<=z;ai++)
            {for(int j=0;j<k+5;j++)
                {nice[ai][j]=nice[ai-1][j];
                    if(j>=b[ai-1]){nice[ai][j]|=nice[ai-1][j-b[ai-1]];}
                }
            }
            //cout<<"OP\n";
            //for(auto x:b){cout<<x<<"\n";}
            /*for(int ai=0;ai<k+3;ai++)
                {if(nice[z][ai]){cout<<ai<<"\n";}}*/
        for(int ai=0;ai<k+3;ai++)
            {if(nice[z][ai])
                {int req=max((int)0,m-ai);
                 int op=max((int)0,n-(k-ai-a[i]));
                 //cout<<req<<" "<<op<<"\n";
                 if(req+op>a[i]){continue;}
                 maxa=min(maxa,req*op);
                }
            }
        //cout<<maxa<<"\n";
        }
    cout<<maxa<<"\n";
    }
}