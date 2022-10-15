#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long


int ans[100005];

vector<int> factors[100005];

int temp[100005];//has to be 0 at end

int tempans[100005];//has to be 0 at end

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(ans,0,sizeof(ans));
    memset(temp,0,sizeof(temp));
    memset(tempans,0,sizeof(tempans));
    for(int i=1;i<100005;i++)
        {
            for(int j=i;j<100005;j+=i){factors[j].push_back(i);}
        }

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}

    for(int i=n;i>=1;i--)
        {
            //cout<<i<<"\n";
            vector<int> p;
            for(int j=i;j<=n;j+=i)
                {
                    for(auto x:factors[a[j-1]])
                        {
                                if(temp[x]>=1){temp[x]++;}
                                else{temp[x]++;p.push_back(x);}
                        }
                }
            sort(p.begin(),p.end());
            reverse(p.begin(),p.end());
            for(auto x:p)
                {
                    int z=temp[x];
                    z=(z*z);
                    tempans[x]+=z;
                    for(auto y:factors[x])
                        {
                            if(temp[y] && y!=x)
                                {
                                    tempans[y]-=tempans[x];
                                }
                        }
                }
            /*for(auto x:p)
                {
                    cout<<"FF"<<x<<" "<<temp[x]<<" "<<tempans[x]<<"\n";
                }*/
            int lol=0;
            for(auto x:p)
                {
                    lol+=(x*tempans[x]);
                    tempans[x]=0;
                    temp[x]=0;
                }
            //cout<<lol<<"\n";
            lol%=mod;
            ans[i]+=lol;
            ans[i]%=mod;
            for(auto x:factors[i])
                {
                    if(x==i){continue;}
                    ans[x]-=ans[i];
                    ans[x]+=mod;
                    ans[x]%=mod;
                }
        }
    int finale=0;
    for(int i=1;i<=n;i++)
        {
            //cout<<ans[i]<<"YY\n";
            finale+=(i*ans[i]);
            finale%=mod;
        }
    cout<<finale;
}