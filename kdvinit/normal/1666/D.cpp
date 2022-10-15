#include<bits/stdc++.h>
using namespace std;
#define int long long




int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        {
            string a,b;
            cin>>a>>b;
            int n=a.size();
            int m=b.size();
            int curr=m-1;
            int poss=1;
            set<int> s;
            for(int i=n-1;i>=0;i--)
                {
                    if(curr>=0 && a[i]==b[curr])
                        {
                            for(int j=i+1;j<n;j++)
                                {
                                    if(a[j]==a[i] && s.find(j)==s.end())
                                        {
                                            poss=0;break;
                                        }
                                }
                            if(poss==0){break;}
                            curr--;
                            s.insert(i);
                        }
                    else
                        {
                            continue;
                        }
                }
            //cout<<curr<<" "<<poss<<"HH\n";
            if(poss && curr==-1){cout<<"YES\n";}
            else{cout<<"NO\n";}
        }

}