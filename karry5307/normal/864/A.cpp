#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cards[101];
ll card,cnt,kind;
vector<ll>v;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
    	cin>>card;
    	cards[card]++;
	}
	for(register int i=0;i<101;i++)
    {
    	if(cards[i])
		{
			v.push_back(i); 
		}
	}
	if(v.size()!=2)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		if(cards[v[0]]!=cards[v[1]])
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl<<v[0]<<" "<<v[1];
		}
	}
}