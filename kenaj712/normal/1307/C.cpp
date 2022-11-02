#include<bits/stdc++.h>
using namespace std;
vector<int> v[30];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    long long maks=0;
    for(int x=0;x<a.size();x++)
        v[a[x]-'a'].push_back(x);
    for(int x=0;x<26;x++)
         if(v[x].size()>maks)
            maks=v[x].size();

    for(int x=0;x<26;x++)
        for(int y=0;y<26;y++)
            {
                long long licz=0;
                int pocz=0;
                for(int z=0;z<v[x].size();z++)
                {
                    while(pocz<v[y].size() && v[x][z]>=v[y][pocz])
                        pocz++;
                    licz+=v[y].size()-pocz;
                }
                maks=max(maks,licz);

            }
    cout<<maks;

	return 0;
}