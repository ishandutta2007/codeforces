#include<bits/stdc++.h>
using namespace std;
int licz[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        for(auto x:a)
        {
            if(x=='A')
                licz[0]++;
            else
            {
                if(licz[0]!=0)
                    licz[0]--;
                else
                    licz[1]++;
            }
        }
        cout<<licz[0]+licz[1]%2<<'\n';
        licz[0]=0;
        licz[1]=0;
    }
	return 0;
}