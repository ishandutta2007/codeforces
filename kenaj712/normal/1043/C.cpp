#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string slowo;
    cin>>slowo;
    slowo+='b';
    bool czy=false;
    v.push_back(0);
    for(int x=1;x<slowo.size()-1;x++)
    {
        if(slowo[x]=='a')
        {
            if(slowo[x+1]=='a')
                v.push_back(0);
            else
                v.push_back(1);
        }
        else
        {
            if(slowo[x+1]=='b')
                v.push_back(0);
            else
                v.push_back(1);
        }

    }
    for(int x=0;x<v.size();x++)
        cout<<v[x]<<" ";
	return 0;
}