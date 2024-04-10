/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s;
    cin>>s;

    int n=s.size(),ans=n;
    for(char a='0';a<='9';a++)
    {
        for(char b='0';b<='9';b++)
        {
            int sum=0;
            char x=a;
            for(int i=0;i<n;i++)
            {
                if(s[i]==x)
                {
                    if(x==a) x=b;
                    else x=a;
                }
                else sum++;
            }
            if(a!=b && x==b) sum++;
            ans=min(ans,sum);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}