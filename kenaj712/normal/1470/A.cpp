#include<bits/stdc++.h>
using namespace std;
int licz[1000005];
long long tab[1000005];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        for(int x=0;x<a;x++)
        {
            int c;
            cin>>c;
            v.push_back(c);
            licz[c]++;
        }
        long long sum=0;
        sort(v.begin(),v.end());
        for(int x=1;x<=b;x++)
        {
            cin>>tab[x];
            if(x<=a)
                sum += tab[x];
        }

        int zlicz = 0;
        for(int x=1;x<=b;x++)
        {
            if(licz[x]>x)
            {
                zlicz+=licz[x] - x;
                licz[x] = x;
            }
            licz[x+1] += licz[x];
        }
        for(int x=0;x<zlicz;x++)
        {
            sum -= tab[a-x];
            sum += tab[v[x]];
        }
        long long mini = sum;
       // cout<<sum<<'\n';
        for(int x=zlicz;x<a;x++)
        {
            sum-=tab[a-x];
            sum+=tab[v[x]];
            mini = min(mini , sum);
           // cout<<sum<<'\n';
        }
        cout<<mini<<'\n';
        for(int x=1;x<=max(a,b+1);x++)
        {
            licz[x] = 0;
            tab[x] = 0;
        }

        v.resize(0);
    }
	return 0;
}